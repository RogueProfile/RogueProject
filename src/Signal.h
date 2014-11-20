#ifndef SIGNAL_H__
#define SIGNAL_H__

#include <functional>
#include <list>
#include <memory>

template<typename>
class SignalConnection;

template<typename>
class Signal;

template<typename R, typename... Args>
class Signal<R (Args...)>
{
    template<typename>
    friend class SignalConnection;
public:
    using FunctionType = std::function<R (Args...)>;
    using ConnectionListType = 
        std::list<std::pair<SignalConnection<R (Args...)>*, FunctionType>>;

    Signal():
        m_self_address(std::make_unique<Signal<R (Args...)>*>(this)) {}

    ~Signal()
    {
        clear();
    }

    Signal(const Signal& other) = delete;
    Signal(Signal&& other) noexcept:
        m_self_address(std::move(other.m_self_address))
    {
        m_connections.splice(m_connections.end(), other.m_connections);
        *m_self_address = this;
    }

    Signal& operator =(const Signal& other) = delete;
    Signal& operator =(Signal&& other) noexcept
    {
        clear();
        m_connections.splice(m_connections.end(), other.m_connections);
        m_self_address = std::move(other.m_self_address);
        *m_self_address = this;
        return *this;
    }

    void emit(Args... args) const
    {
        for(const auto& connection : m_connections)
        {
            connection.second(args...);
        }
    }

    SignalConnection<R (Args...)> connect(FunctionType fn)
    {
        m_connections.emplace_back(nullptr, std::move(fn));
        auto it = --m_connections.end();
        auto connection = SignalConnection<R (Args...)>(m_self_address.get(), it);
        it->first = &connection;
        return connection;
    }

    void clear()
    {
        for(const auto& connection : m_connections)
        {
            if(connection.first != nullptr)
            {
                connection.first->release();
            }
        }
        m_connections.clear();
    }

protected:
    void disconnect(typename ConnectionListType::iterator& it)
    {
        m_connections.erase(it);
    }

    void disassociate_connection(typename ConnectionListType::iterator& it)
    {
        it->first = nullptr;
    }

    ConnectionListType m_connections;
    std::unique_ptr<Signal<R (Args...)>*> m_self_address;
};

template<typename R, typename... Args>
class SignalConnection<R (Args...)>
{
public:
    using TargetType = typename Signal<R (Args...)>::ConnectionListType::iterator;

    SignalConnection() = default;

    SignalConnection(Signal<R (Args...)>** signal, TargetType target):
        m_signal(signal), m_target(std::move(target)) {}

    ~SignalConnection()
    {
        disconnect();
    }

    SignalConnection(const SignalConnection& other) = delete;
    SignalConnection(SignalConnection&& other):
        m_signal(other.m_signal), m_target(std::move(other.m_target))
    {
        other.m_signal = nullptr;
    }

    SignalConnection& operator =(const SignalConnection& other) = delete;
    SignalConnection& operator =(SignalConnection&& other)
    {
        disconnect();
        std::swap(m_signal, other.m_signal);
        m_target = std::move(other.m_target);
        return *this;
    }

    void disconnect()
    {
        if(m_signal != nullptr)
        {
            (*m_signal)->disconnect(m_target);
        }
        m_signal = nullptr;
    }

    void release()
    {
        (*m_signal)->disassociate_connection(m_target);
        m_signal = nullptr;
    }

    bool is_connected() const {return m_signal != nullptr;}

protected:
    Signal<R (Args...)>** m_signal = nullptr;
    TargetType m_target;
};

#endif

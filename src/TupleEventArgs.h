#ifndef TUPLEEVENTARGS_H__
#define TUPLEEVENTARGS_H__

#include "EventArgs.h"

#include <tuple>

template<typename... Args>
class TupleEventArgs: public EventArgs
{
public:
    TupleEventArgs(Args... args):
        m_args(std::move(args)...) {}

    virtual ~TupleEventArgs() = default;

    TupleEventArgs(const TupleEventArgs& other) = delete;
    TupleEventArgs(TupleEventArgs&& other) noexcept = delete;
    TupleEventArgs& operator =(const TupleEventArgs& other) = delete;
    TupleEventArgs& operator =(TupleEventArgs&& other) noexcept = delete;

    const std::tuple<Args...>& args() const {return m_args;}

    template<typename Fn>
    void call_fn(const Fn& fn) const
    {
        call_fn_internal(fn, std::index_sequence_for<Args...>{});
    }

protected:
    template<typename Fn, size_t... S>
    void call_fn_internal(const Fn& fn, std::index_sequence<S...>) const
    {
        fn(std::get<S>(m_args)...);
    }

    std::tuple<Args...> m_args;
private:
};


#endif
    

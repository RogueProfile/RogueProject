#ifndef EVENTMANAGER_H__
#define EVENTMANAGER_H__

#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <type_traits>

#include "Signal.h"
#include "Event.h"

#include "TupleEventArgs.h"

class EventManager
{
public:
    using EventConnection = SignalConnection<void (const EventArgs&)>;

    EventManager() = default;
    ~EventManager() = default;

    EventManager(const EventManager& other) = delete;
    EventManager(EventManager&& other) noexcept = delete;
    EventManager& operator =(const EventManager& other) = delete;
    EventManager& operator =(EventManager&& other) noexcept = delete;

    bool has_event(const std::string& name) const;

    EventConnection register_event_handler(const std::string& name,
           std::function<void (const EventArgs&)> event_handler);

    template<typename... Args>
    EventConnection register_event_handler(const std::string& name,
            std::function<void (Args...)> event_handler);

    Event& get_event(const std::string& name);

    void trigger(const std::string& name)
    {
        return trigger(get_event(name));
    }

    void trigger(const Event& event);
    void trigger(const std::string& name, const EventArgs& args)
    {
        return trigger(get_event(name), args);
    }

    void trigger(const Event& event, const EventArgs& args);

    template<typename... Args>
    void trigger(const std::string& name, Args... args)
    {
        return trigger(get_event(name), args...);
    }

    template<typename... Args>
    void trigger(const Event& event, Args... args);

protected:
    std::unordered_map<std::string, std::unique_ptr<Event>> m_events_by_name;
private:
};


template<typename... Args>
inline EventManager::EventConnection EventManager::register_event_handler(const std::string& name, 
    std::function<void (Args...)> event_handler)
{
    auto outer_fn = [inner_fn=std::move(event_handler)](const EventArgs& e)
    {
        const auto& args = dynamic_cast<
            const TupleEventArgs<
                typename std::decay<Args>::type...>&>(e);
        args.call_fn(inner_fn);     
    }; 
    return register_event_handler(name, std::move(outer_fn));
}
 
template<typename... Args>
inline void EventManager::trigger(const Event& event, Args... args)
{
    TupleEventArgs<Args...> packed_args(args...); 
    event.signal().emit(packed_args);
}
 
#endif
    

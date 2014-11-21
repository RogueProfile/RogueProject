#include "EventManager.h"

#include "Event.h"

#include "Exceptions/InvalidEventError.h"

bool EventManager::has_event(const std::string& name) const
{
    return m_events_by_name.find(name) != m_events_by_name.end(); 
}
 
EventManager::EventConnection EventManager::register_event_handler(const std::string& name,
       std::function<void (const EventArgs&)> event_handler)
{
    auto event_it = m_events_by_name.find(name);
    if(event_it == m_events_by_name.end())
    {
        auto ret = m_events_by_name.emplace(name, std::make_unique<Event>(name)); 
        event_it = ret.first;
    }    

    return event_it->second->signal().connect(std::move(event_handler));
}
 
Event& EventManager::get_event(const std::string& name)
{
    auto event_it = m_events_by_name.find(name);
    if(event_it != m_events_by_name.end())
    {
        return *event_it->second;
    } 
    else
    {
        throw InvalidEventError(name);
    }
}
 
void EventManager::trigger(const Event& event)
{
    NullEventArgs args;
    event.signal().emit(args); 
}
 
void EventManager::trigger(const Event& event, const EventArgs& args)
{
    event.signal().emit(args); 
}
 

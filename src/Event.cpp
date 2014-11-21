#include "Event.h"

Event::Event(std::string name):
    m_name(std::move(name))
{
 
}
 
Event::Event(Event&& other) noexcept:
    m_name(std::move(other.m_name)), m_signal(std::move(other.m_signal))
{
}
 
Event& Event::operator=(Event&& other) noexcept
{
    m_name = std::move(other.m_name);
    m_signal = std::move(other.m_signal);
    return *this; 
}
 

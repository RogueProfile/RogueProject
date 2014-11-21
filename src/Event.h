#ifndef EVENT_H__
#define EVENT_H__

#include <string>

#include "Signal.h"
#include "EventArgs.h"

class Event
{
public:
    explicit Event(std::string name);
    ~Event() = default;

    Event(const Event& other) = default;
    Event(Event&& other) noexcept;
    Event& operator =(const Event& other) = default;
    Event& operator =(Event&& other) noexcept;

    const std::string& name() const {return m_name;}

    Signal<void (const EventArgs&)>& signal() {return m_signal;}
    const Signal<void (const EventArgs&)>& signal() const {return m_signal;}

protected:
    std::string m_name;
    Signal<void (const EventArgs&)> m_signal; 
private:
};


#endif
    

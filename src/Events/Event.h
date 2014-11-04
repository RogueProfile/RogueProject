#ifndef EVENT_H__
#define EVENT_H__

namespace event
{

enum class EventType
{
    Quit,
    KeyUp,
    KeyDown,
    Unknown
};

class Event
{
public:

    explicit Event(EventType type);
    virtual ~Event() = default;

    Event(const Event& other) = default;
    Event(Event&& other) noexcept = default;
    Event& operator =(const Event& other) = default;
    Event& operator =(Event&& other) noexcept = default;

    EventType type() const {return m_type;}

protected:
    EventType m_type;
private:
};

}


#endif
    

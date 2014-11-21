#ifndef WINDOWEVENT_H__
#define WINDOWEVENT_H__

namespace event
{

enum class EventType
{
    Quit,
    KeyUp,
    KeyDown,
    Unknown
};

class WindowEvent
{
public:

    explicit WindowEvent(EventType type);
    virtual ~WindowEvent() = default;

    WindowEvent(const WindowEvent& other) = default;
    WindowEvent(WindowEvent&& other) noexcept = default;
    WindowEvent& operator =(const WindowEvent& other) = default;
    WindowEvent& operator =(WindowEvent&& other) noexcept = default;

    EventType type() const {return m_type;}

protected:
    EventType m_type;
private:
};

}


#endif
    

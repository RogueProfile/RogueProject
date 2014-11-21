#ifndef WINDOWEVENT_H__
#define WINDOWEVENT_H__

#include "Visitor.h"

namespace event
{

enum class EventType
{
    Quit,
    KeyUp,
    KeyDown,
    Unknown
};

class KeyboardEvent;
class WindowEvent;

class EventVisitor
{
public:
    virtual void visit(const WindowEvent& object) {};
    virtual void visit(const KeyboardEvent& object) {};
    virtual ~EventVisitor() = default;
};

class WindowEvent: public VisitableImpl<WindowEvent, EventVisitor>
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
    

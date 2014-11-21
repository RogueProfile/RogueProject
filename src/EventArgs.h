#ifndef EVENTARGS_H__
#define EVENTARGS_H__

class EventArgs
{
public:
    EventArgs() = default;
    virtual ~EventArgs() = default;

    EventArgs(const EventArgs& other) = default;
    EventArgs(EventArgs&& other) noexcept = default;
    EventArgs& operator =(const EventArgs& other) = default;
    EventArgs& operator =(EventArgs&& other) noexcept = default;
};

class NullEventArgs: public EventArgs
{
public:
    NullEventArgs() = default;
    virtual ~NullEventArgs() = default;

    NullEventArgs(const NullEventArgs& other) = default;
    NullEventArgs(NullEventArgs&& other) noexcept = default;
    NullEventArgs& operator =(const NullEventArgs& other) = default;
    NullEventArgs& operator =(NullEventArgs&& other) noexcept = default;
};

#endif
    

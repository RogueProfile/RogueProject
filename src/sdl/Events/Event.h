#ifndef EVENT_H__
#define EVENT_H__

namespace sdl
{

class Event
{
public:
    enum class Type
    {
        Quit,
        Unknown
    };

    explicit Event(Type type);
    ~Event() = default;

    Event(const Event& other) = default;
    Event(Event&& other) noexcept = default;
    Event& operator =(const Event& other) = default;
    Event& operator =(Event&& other) noexcept = default;

    Type type() const {return m_type;}

protected:
    Type m_type;
private:
};

}


#endif
    

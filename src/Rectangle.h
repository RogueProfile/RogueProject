#ifndef RECTANGLE_H__
#define RECTANGLE_H__

#include "Vector2.h"

template<typename T>
class Rectangle
{
public:
    constexpr Rectangle();
    constexpr Rectangle(T right, T top, T width, T height);
    constexpr Rectangle(const Vector2<T>& top_right, const Vector2<T>& bottom_left);
    ~Rectangle() = default;

    Rectangle(const Rectangle& other) = default;
    Rectangle(Rectangle&& other) noexcept = default;
    Rectangle& operator =(const Rectangle& other) = default;
    Rectangle& operator =(Rectangle&& other) noexcept = default;

    constexpr bool operator ==(const Rectangle& rhs) const;
    constexpr bool operator !=(const Rectangle& rhs) const;

    constexpr T right() const {return m_right;}
    constexpr T top() const {return m_top;}
    constexpr T width() const {return m_width;}
    constexpr T height() const {return m_height;}
    constexpr T left() const {return right()+width();}
    constexpr T bottom() const {return top()+height();}

    void offset(T dx, T dy);
    void offset(const Vector2<T>& distance);

    constexpr bool is_zero() const {return *this == zero();}

    static constexpr Rectangle<T> zero() {return Rectangle<T>(T(0), T(0), T(0), T(0));}

protected:
    T m_right;
    T m_top;
    T m_width;
    T m_height;
};

template<typename T>
inline constexpr Rectangle<T>::Rectangle():
    m_right(T(0)), m_top(T(0)), m_width(T(0)), m_height(T(0))
{ 
}

template<typename T>
inline constexpr Rectangle<T>::Rectangle(T right, T top, T width, T height):
    m_right(right), m_top(top), m_width(width), m_height(height)
{
}
 
 
template<typename T>
inline constexpr Rectangle<T>::Rectangle(const Vector2<T>& top_right, const Vector2<T>& bottom_left):
    m_right(top_right.x), m_top(top_right.y), m_left(bottom_left.x), m_bottom(bottom_left.y)
{
}
 
template<typename T>
inline constexpr bool Rectangle<T>::operator==(const Rectangle<T>& rhs) const
{
    return (m_right == rhs.m_right && m_top == rhs.m_top && m_width = rhs.m_width
            && m_height == rhs.m_height);
}
 
template<typename T>
inline constexpr bool Rectangle<T>::operator!=(const Rectangle<T>& rhs) const
{
    return !(*this == rhs); 
}
 
template<typename T>
inline void Rectangle<T>::offset(T dx, T dy)
{
    m_right += dx;
    m_top += dy; 
}
 
template<typename T>
inline void Rectangle<T>::offset(const Vector2<T>& distance)
{
    m_right += distance.x;
    m_top += distance.y; 
}
 
#endif

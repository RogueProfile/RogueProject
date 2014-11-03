#ifndef RECTANGLE_H__
#define RECTANGLE_H__

#include "Vector2.h"

template<typename T>
class Rectangle
{
public:
    constexpr Rectangle();
    constexpr Rectangle(T left, T bottom, T width, T height);
    constexpr Rectangle(const Vector2<T>& bottom_left, const Vector2<T>& top_right);
    ~Rectangle() = default;

    Rectangle(const Rectangle& other) = default;
    Rectangle(Rectangle&& other) noexcept = default;
    Rectangle& operator =(const Rectangle& other) = default;
    Rectangle& operator =(Rectangle&& other) noexcept = default;

    constexpr bool operator ==(const Rectangle& rhs) const;
    constexpr bool operator !=(const Rectangle& rhs) const;

    constexpr T left() const {return m_left;}
    constexpr T bottom() const {return m_bottom;}
    constexpr T width() const {return m_width;}
    constexpr T height() const {return m_height;}
    constexpr T right() const {return left()+width();}
    constexpr T top() const {return bottom()+height();}

    void offset(T dx, T dy);
    void offset(const Vector2<T>& distance);

    constexpr bool is_zero() const {return *this == zero();}

    static constexpr Rectangle<T> zero() {return Rectangle<T>(T(0), T(0), T(0), T(0));}

    static constexpr Rectangle<T> from_vertices(T left, T bottom, T right, T top);

protected:
    T m_left;
    T m_bottom;
    T m_width;
    T m_height;
};

using Rectangled = Rectangle<double>;
using Rectanglef = Rectangle<float>;
using Rectanglei = Rectangle<int>;

template<typename T>
inline constexpr Rectangle<T>::Rectangle():
    m_left(T(0)), m_bottom(T(0)), m_width(T(0)), m_height(T(0))
{ 
}

template<typename T>
inline constexpr Rectangle<T>::Rectangle(T left, T bottom, T width, T height):
    m_left(left), m_bottom(bottom), m_width(width), m_height(height)
{
}
 
 
template<typename T>
inline constexpr Rectangle<T>::Rectangle(const Vector2<T>& bottom_left, const Vector2<T>& top_right):
    m_left(bottom_left.x), m_bottom(bottom_left.y), m_width(top_right.x - bottom_left.x),
    m_height(top_right.y - bottom_left.y)
{
}
 
template<typename T>
inline constexpr bool Rectangle<T>::operator==(const Rectangle<T>& rhs) const
{
    return (m_left == rhs.m_left && m_bottom == rhs.m_bottom && m_width = rhs.m_width
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
    m_left += dx;
    m_bottom += dy; 
}
 
template<typename T>
inline void Rectangle<T>::offset(const Vector2<T>& distance)
{
    m_left += distance.x;
    m_bottom += distance.y; 
}
 
template<typename T>
inline constexpr Rectangle<T> Rectangle<T>::from_vertices(T left, T bottom, T right, T top)
{
    return Rectangle<T>(left, bottom, top - bottom, right - left); 
}
 
#endif

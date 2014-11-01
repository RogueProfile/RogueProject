#ifndef VECTOR2_H__
#define VECTOR2_H__

#include <utility>
#include <cmath>
#include <ostream>

#include "Angle.h"

template<typename T>
class Vector2
{
public:
    constexpr Vector2();
    ~Vector2() = default;

    constexpr Vector2(T x_val, T y_val);

    constexpr Vector2(const Vector2& lhs) = default;
    constexpr Vector2(Vector2&& lhs);
    constexpr Vector2<T>& operator =(const Vector2<T>& rhs) = default;
    constexpr Vector2<T>& operator =(Vector2<T>&& rhs);

    constexpr bool operator ==(const Vector2<T>& rhs) const;
    constexpr bool operator !=(const Vector2<T>& rhs) const;

    constexpr Vector2<T> operator +(Vector2<T> rhs) const;
    constexpr Vector2<T> operator -(Vector2<T> rhs) const;
    constexpr Vector2<T> operator *(T rhs) const;
    constexpr Vector2<T> operator /(T rhs) const;
    constexpr Vector2<T> operator -() const;

    Vector2<T>& operator +=(const Vector2<T>& rhs);
    Vector2<T>& operator -=(const Vector2<T>& rhs);
    Vector2<T>& operator *=(T rhs);
    Vector2<T>& operator /=(T rhs);

    constexpr T dot(const Vector2<T>& rhs) const;

    constexpr T magnitude_squared() const;
    T magnitude() const;

    Radians<T> angle_from_x_axis() const;

    template<typename U>
    friend constexpr Vector2<U> operator *(U lhs, Vector2<U> rhs);
    
    static constexpr Vector2<T> zero() {return Vector2<T>(T{0}, T{0});}
    static constexpr Vector2<T> unit_x() {return Vector2<T>(T{1}, T{0});}
    static constexpr Vector2<T> unit_y() {return Vector2<T>(T{0}, T{1});}

    T x;
    T y;
};

using Vector2d = Vector2<double>;
using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;
using Vector2ui = Vector2<unsigned int>;

template<typename T>
void swap(Vector2<T>& lhs, Vector2<T>& rhs);

template<typename T>
std::ostream& operator <<(std::ostream& stream, const Vector2<T>& rhs)
{
    stream << "(" << rhs.x << ", " << rhs.y << ")";
    return stream;
}

template<typename T>
inline constexpr Vector2<T>::Vector2():
    x(T{0}), y(T{0})
{
}
 
template<typename T>
inline constexpr Vector2<T>::Vector2(T x_val, T y_val):
   x(x_val), y(y_val) 
{
}
 
template<typename T>
inline constexpr Vector2<T>::Vector2(Vector2<T>&& lhs):
    x(std::move(lhs.x)), y(std::move(lhs.y))
{
}

template<typename T>
void swap(Vector2<T>& lhs, Vector2<T>& rhs)
{
    using std::swap;
    swap(lhs.x, rhs.x);
    swap(lhs.y, rhs.y);
}
 
template<typename T>
inline constexpr Vector2<T>& Vector2<T>::operator=(Vector2<T>&& rhs)
{
    x = std::move(rhs.x); 
    y = std::move(rhs.y);
    return *this;
}
 
template<typename T>
inline constexpr bool Vector2<T>::operator==(const Vector2<T>& rhs) const
{
    return (x == rhs.x && y == rhs.y); 
}
 
template<typename T>
inline constexpr bool Vector2<T>::operator!=(const Vector2<T>& rhs) const
{
    return !(*this == rhs); 
}
 
template<typename T>
inline constexpr Vector2<T> Vector2<T>::operator+(Vector2<T> rhs) const
{
    return Vector2<T>(x + rhs.x, y + rhs.y); 
}
 
template<typename T>
inline constexpr Vector2<T> Vector2<T>::operator-(Vector2<T> rhs) const
{
    return Vector2<T>(x - rhs.x, y - rhs.y); 
}
 
template<typename T>
inline constexpr Vector2<T> Vector2<T>::operator*(T rhs) const
{
    return Vector2<T>(x * rhs, y * rhs); 
}
 
template<typename T>
inline constexpr Vector2<T> Vector2<T>::operator/(T rhs) const
{
 
    return Vector2<T>(x / rhs, y / rhs); 
}
 
template<typename T>
inline constexpr Vector2<T> Vector2<T>::operator-() const
{
    return Vector2<T>(-x, -y); 
}

template<typename T>
constexpr Vector2<T> operator *(T lhs, Vector2<T> rhs)
{
    return rhs + lhs;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& rhs)
{
    x += rhs.x;
    y += rhs.y;    
    return *this;
}
 
template<typename T>
inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& rhs)
{
    x -= rhs.x;
    y -= rhs.y;    
    return *this;
}
 
template<typename T>
inline Vector2<T>& Vector2<T>::operator*=(T rhs)
{
    x *= rhs;
    y *= rhs;
    return *this; 
}
 
template<typename T>
inline Vector2<T>& Vector2<T>::operator/=(T rhs)
{
    x /= rhs;
    y /= rhs;
    return *this; 
}
 
template<typename T>
inline constexpr T Vector2<T>::dot(const Vector2<T>& rhs) const
{
    return x * rhs.x + y * rhs.y;
}
 
template<typename T>
inline constexpr T Vector2<T>::magnitude_squared() const
{
    return x*x + y*y; 
}
 
template<typename T>
inline T Vector2<T>::magnitude() const
{
    using std::sqrt;
    return sqrt(x*x + y*y); 
}
 
template<typename T>
inline Radians<T> Vector2<T>::angle_from_x_axis() const
{
    using std::atan2;
    return Radians<T>(atan2(y, x));
}
 
#endif

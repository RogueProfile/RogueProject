#ifndef VECTOR3_H__
#define VECTOR3_H__

#include <utility>
#include <cmath>
#include <ostream>

#include "Angle.h"

template<typename T>
class Vector3
{
public:
    constexpr Vector3();
    ~Vector3() = default;

    constexpr Vector3(T x_val, T y_val, T z_val);

    constexpr Vector3(const Vector3& lhs) = default;
    constexpr Vector3(Vector3&& lhs);
    constexpr Vector3<T>& operator =(const Vector3<T>& rhs) = default;
    constexpr Vector3<T>& operator =(Vector3<T>&& rhs);

    constexpr bool operator ==(const Vector3<T>& rhs) const;
    constexpr bool operator !=(const Vector3<T>& rhs) const;

    constexpr Vector3<T> operator +(Vector3<T> rhs) const;
    constexpr Vector3<T> operator -(Vector3<T> rhs) const;
    constexpr Vector3<T> operator *(T rhs) const;
    constexpr Vector3<T> operator /(T rhs) const;
    constexpr Vector3<T> operator -() const;

    Vector3<T>& operator +=(const Vector3<T>& rhs);
    Vector3<T>& operator -=(const Vector3<T>& rhs);
    Vector3<T>& operator *=(T rhs);
    Vector3<T>& operator /=(T rhs);

    constexpr T dot(const Vector3<T>& rhs) const;
    constexpr T cross(const Vector3<T>& rhs) const;

    constexpr T magnitude_squared() const;
    T magnitude() const;


    template<typename U>
    friend constexpr Vector3<U> operator *(U lhs, Vector3<U> rhs);
    
    static constexpr Vector3<T> zero() {return Vector3<T>(T{0}, T{0}, T{0});}
    static constexpr Vector3<T> unit_x() {return Vector3<T>(T{1}, T{0}, T{0});}
    static constexpr Vector3<T> unit_y() {return Vector3<T>(T{0}, T{1}, T{0});}
    static constexpr Vector3<T> unit_z() {return Vector3<T>(T{0}, T{0}, T{0});}

    T x;
    T y;
    T z;
};

using Vector3d = Vector3<double>;
using Vector3f = Vector3<float>;
using Vector3i = Vector3<int>;
using Vector3ui = Vector3<unsigned int>;

template<typename T>
void swap(Vector3<T>& lhs, Vector3<T>& rhs);

template<typename T>
std::ostream& operator <<(std::ostream& stream, const Vector3<T>& rhs)
{
    stream << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")";
    return stream;
}

template<typename T>
inline constexpr Vector3<T>::Vector3():
    x(T{0}), y(T{0}), z(T{0})
{
}
 
template<typename T>
inline constexpr Vector3<T>::Vector3(T x_val, T y_val, T z_val):
   x(x_val), y(y_val), z(z_val) 
{
}
 
template<typename T>
inline constexpr Vector3<T>::Vector3(Vector3<T>&& lhs):
    x(std::move(lhs.x)), y(std::move(lhs.y)), z(std::move(lhs.z))
{
}

template<typename T>
void swap(Vector3<T>& lhs, Vector3<T>& rhs)
{
    using std::swap;
    swap(lhs.x, rhs.x);
    swap(lhs.y, rhs.y);
    swap(lhs.z, rhs.z);
}
 
template<typename T>
inline constexpr Vector3<T>& Vector3<T>::operator=(Vector3<T>&& rhs)
{
    x = std::move(rhs.x); 
    y = std::move(rhs.y);
    z = std::move(rhs.z);
    return *this;
}
 
template<typename T>
inline constexpr bool Vector3<T>::operator==(const Vector3<T>& rhs) const
{
    return (x == rhs.x && y == rhs.y && z == rhs.z); 
}
 
template<typename T>
inline constexpr bool Vector3<T>::operator!=(const Vector3<T>& rhs) const
{
    return !(*this == rhs); 
}
 
template<typename T>
inline constexpr Vector3<T> Vector3<T>::operator+(Vector3<T> rhs) const
{
    return Vector3<T>(x + rhs.x, y + rhs.y, z + rhs.z); 
}
 
template<typename T>
inline constexpr Vector3<T> Vector3<T>::operator-(Vector3<T> rhs) const
{
    return Vector3<T>(x - rhs.x, y - rhs.y, z - rhs.z); 
}
 
template<typename T>
inline constexpr Vector3<T> Vector3<T>::operator*(T rhs) const
{
    return Vector3<T>(x * rhs, y * rhs, z * rhs); 
}
 
template<typename T>
inline constexpr Vector3<T> Vector3<T>::operator/(T rhs) const
{
 
    return Vector3<T>(x / rhs, y / rhs, z / rhs); 
}
 
template<typename T>
inline constexpr Vector3<T> Vector3<T>::operator-() const
{
    return Vector3<T>(-x, -y, -z); 
}

template<typename T>
constexpr Vector3<T> operator *(T lhs, Vector3<T> rhs)
{
    return rhs * lhs;
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& rhs)
{
    x += rhs.x;
    y += rhs.y;  
    z += rhs.z; 
    return *this;
}
 
template<typename T>
inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& rhs)
{
    x -= rhs.x;
    y -= rhs.y;    
    z -= rhs.z;
    return *this;
}
 
template<typename T>
inline Vector3<T>& Vector3<T>::operator*=(T rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this; 
}
 
template<typename T>
inline Vector3<T>& Vector3<T>::operator/=(T rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this; 
}
 
template<typename T>
inline constexpr T Vector3<T>::dot(const Vector3<T>& rhs) const
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}
 
template<typename T>
inline constexpr T Vector3<T>::cross(const Vector3<T>& rhs) const
{
    return Vector3<T>(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}
 
template<typename T>
inline constexpr T Vector3<T>::magnitude_squared() const
{
    return x*x + y*y + z*z; 
}
 
template<typename T>
inline T Vector3<T>::magnitude() const
{
    using std::sqrt;
    return sqrt(x*x + y*y + z*z); 
}
 
 
#endif

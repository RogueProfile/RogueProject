#ifndef ANGLE_H__
#define ANGLE_H__

#include <cmath>
#include <ostream>

#include "Constants.h"

template<typename T>
class Degrees;

template<typename T>
class Radians
{
public:
    explicit constexpr Radians(T val);
    ~Radians() = default;

    constexpr Radians(const Radians& rhs) = default;
    constexpr Radians(Radians&& rhs) = default;
    constexpr Radians& operator =(const Radians& rhs) = default;
    constexpr Radians& operator =(Radians&& rhs) = default;

    constexpr Degrees<T> to_degrees() const;

    T value;
};

template<typename T>
class Degrees
{
public:
    explicit constexpr Degrees(T val);
    ~Degrees() = default;

    constexpr Degrees(const Degrees& rhs) = default;
    constexpr Degrees(Degrees&& rhs) = default;
    constexpr Degrees& operator =(const Degrees& rhs) = default;
    constexpr Degrees& operator =(Degrees&& rhs) = default;

    constexpr Radians<T> to_radians() const;
    constexpr void clamp_value();

    T value;
};

template<typename T>
std::ostream& operator <<(std::ostream& stream, Radians<T> rhs)
{
    stream << rhs.value;
    return stream;
}

template<typename T>
std::ostream& operator <<(std::ostream& stream, Degrees<T> rhs)
{
    stream << rhs.value;
    return stream;
}

template<typename T>
T sin(Radians<T> arg)
{
    using std::sin;
    return T(sin(arg.value));
}

template<typename T>
T sin(Degrees<T> arg)
{
    using std::sin;
    return T(sin(arg.to_radians().value));
}

template<typename T>
T cos(Radians<T> arg)
{
    using std::cos;
    return T(cos(arg.value));
}

template<typename T>
T cos(Degrees<T> arg)
{
    using std::cos;
    return T(cos(arg.to_radians().value));
}

template<typename T>
T tan(Radians<T> arg)
{
    using std::tan;
    return T(tan(arg.value));
}

template<typename T>
T tan(Degrees<T> arg)
{
    using std::tan;
    return T(tan(arg.to_radians().value));
}

template<typename T>
Radians<T> asin(T arg)
{
    using std::asin;
    return Radians<T>(asin(arg));
}

template<typename T>
Radians<T> acos(T arg)
{
    using std::acos;
    return Radians<T>(acos(arg));
}

template<typename T>
Radians<T> atan(T arg)
{
    using std::atan;
    return Radians<T>(atan(arg));
}

template<typename T>
Radians<T> atan2(T x, T y)
{
    using std::atan2;
    return Radians<T>(atan2(y, x));
}

template<typename T>
inline constexpr Radians<T>::Radians(T val):
    value(val)
{
}

template<typename T>
inline constexpr Degrees<T> Radians<T>::to_degrees() const
{
    return Degrees<T>(value * (T(180) / PI<T>)); 
}
 
template<typename T>
inline constexpr Degrees<T>::Degrees(T val):
    value(val)
{
}
 
template<typename T>
inline constexpr Radians<T> Degrees<T>::to_radians() const
{
    return Radians<T>(value * (PI<T> / T(180))); 
}
 
template<typename T>
inline constexpr void Degrees<T>::clamp_value()
{
    value = std::fmod(value, std::copysignf(360,value));
}
 
#endif

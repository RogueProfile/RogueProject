#ifndef MATRIX3_H__
#define MATRIX3_H__

#include <array>
#include "Angle.h"

template<typename T>
class Matrix3
{
public:
    constexpr Matrix3();
    constexpr Matrix3(T m11, T m12, T m13, T m21, T m22, T m23, T m31, T m32, T m33);
    constexpr Matrix3(const std::array<T, 9>& values);
    ~Matrix3() = default;

    constexpr Matrix3(const Matrix3& other) = default;
    constexpr Matrix3(Matrix3&& other) noexcept = default;
    constexpr Matrix3& operator =(const Matrix3& other) = default;
    constexpr Matrix3& operator =(Matrix3&& other) noexcept = default;

    constexpr bool operator ==(const Matrix3<T>& rhs) const;
    constexpr bool operator !=(const Matrix3<T>& rhs) const;

    constexpr Matrix3<T>& operator +=(const Matrix3<T>& rhs);
    constexpr Matrix3<T>& operator -=(const Matrix3<T>& rhs);
    constexpr Matrix3<T>& operator *=(const Matrix3<T>& rhs);
    constexpr Matrix3<T>& operator *=(T value);
    constexpr Matrix3<T>& operator /=(T value);

    constexpr Matrix3<T> operator -() const;

    friend constexpr Matrix3<T> operator *(T value, const Matrix3<T>& matrix) 
        {return matrix * value;}

    static constexpr Matrix3<T> zero();
    static constexpr Matrix3<T> identity();

    std::array<T, 9> val;
private:
};

 
template<typename T>
inline constexpr Matrix3<T>::Matrix3()
{
    val.fill(T(0));
}

template<typename T>
inline constexpr Matrix3<T>::Matrix3(T m11, T m12, T m13, T m21, T m22, T m23, T m31, T m32, T m33):
    val({m11, m12, m13, m21, m22, m23, m31, m32, m33})
{
 
}
 
template<typename T>
inline constexpr Matrix3<T>::Matrix3(const std::array<T, 9>& values):
    val(values)
{
 
}
 
 
template<typename T>
inline constexpr bool Matrix3<T>::operator==(const Matrix3<T>& rhs) const
{
    return val == rhs.val;
}
 
template<typename T>
inline constexpr bool Matrix3<T>::operator!=(const Matrix3<T>& rhs) const
{
    return !(*this == rhs); 
}
 
template<typename T>
inline constexpr Matrix3<T>& Matrix3<T>::operator+=(const Matrix3<T>& rhs)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] += rhs.val[i];
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix3<T>& Matrix3<T>::operator-=(const Matrix3<T>& rhs)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] -= rhs.val[i];
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix3<T>& Matrix3<T>::operator*=(const Matrix3<T>& rhs)
{
    auto old_val = val;
    val[0] = old_val[0] * rhs.val[0] + old_val[1] * rhs.val[3] + old_val[2] * rhs.val[6];
    val[1] = old_val[0] * rhs.val[1] + old_val[1] * rhs.val[4] + old_val[2] * rhs.val[7];
    val[2] = old_val[0] * rhs.val[2] + old_val[1] * rhs.val[5] + old_val[2] * rhs.val[8];

    val[3] = old_val[3] * rhs.val[0] + old_val[4] * rhs.val[3] + old_val[5] * rhs.val[6];
    val[4] = old_val[3] * rhs.val[1] + old_val[4] * rhs.val[4] + old_val[5] * rhs.val[7];
    val[5] = old_val[3] * rhs.val[2] + old_val[4] * rhs.val[5] + old_val[5] * rhs.val[8];

    val[6] = old_val[6] * rhs.val[0] + old_val[7] * rhs.val[3] + old_val[8] * rhs.val[6];
    val[7] = old_val[6] * rhs.val[1] + old_val[7] * rhs.val[4] + old_val[8] * rhs.val[7];
    val[8] = old_val[6] * rhs.val[2] + old_val[7] * rhs.val[5] + old_val[8] * rhs.val[8];  
    return *this;
}
 
template<typename T>
inline constexpr Matrix3<T>& Matrix3<T>::operator*=(T value)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] *= value;
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix3<T>& Matrix3<T>::operator/=(T value)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] /= value;
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix3<T> Matrix3<T>::operator-() const
{
    return -Matrix3<T>(-val[0], -val[1], -val[2], -val[3], -val[4], -val[5], -val[6], -val[7], -val[8], -val[9]); 
}

template<typename T>
inline Matrix3<T> operator+(const Matrix3<T>& lhs, const Matrix3<T>& rhs)
{
    auto tmp(lhs);
    tmp += rhs;
    return tmp;
}
 
template<typename T>
inline Matrix3<T> operator-(const Matrix3<T>& lhs, const Matrix3<T>& rhs)
{
    auto tmp(lhs);
    tmp -= rhs;
    return tmp;
}
template<typename T>
inline Matrix3<T> operator*(const Matrix3<T>& lhs, const Matrix3<T>& rhs)
{
    auto tmp(lhs);
    tmp *= rhs;
    return tmp;
}

template<typename T>
inline Matrix3<T> operator*(const Matrix3<T>& lhs, T rhs)
{
    auto tmp(lhs);
    tmp *= rhs;
    return lhs;
}

template<typename T>
inline constexpr Matrix3<T> Matrix3<T>::zero()
{
    return Matrix3<T>{0, 0, 0, 0, 0, 0, 0, 0, 0}; 
}
 
template<typename T>
inline constexpr Matrix3<T> Matrix3<T>::identity()
{
    return Matrix3<T>{1, 0, 0, 0, 1, 0, 0, 0, 1}; 
}
 
#endif
    

#ifndef MATRIX2_H__
#define MATRIX2_H__

#include <array>

template<typename T>
class Matrix2
{
public:
    constexpr Matrix2();
    constexpr Matrix2(T m11, T m12, T m21, T m22);
    constexpr Matrix2(const std::array<T, 4>& values);
    ~Matrix2() = default;

    constexpr Matrix2(const Matrix2& other) = default;
    constexpr Matrix2(Matrix2&& other) noexcept = default;
    constexpr Matrix2& operator =(const Matrix2& other) = default;
    constexpr Matrix2& operator =(Matrix2&& other) noexcept = default;

    constexpr bool operator ==(const Matrix2<T>& rhs) const;
    constexpr bool operator !=(const Matrix2<T>& rhs) const;

    constexpr Matrix2<T>& operator +=(const Matrix2<T>& rhs);
    constexpr Matrix2<T>& operator -=(const Matrix2<T>& rhs);
    constexpr Matrix2<T>& operator *=(const Matrix2<T>& rhs);
    constexpr Matrix2<T>& operator *=(T value);
    constexpr Matrix2<T>& operator /=(T value);

    constexpr Matrix2<T> operator -() const;

    friend constexpr Matrix2<T> operator *(T value, const Matrix2<T>& matrix) 
        {return matrix * value;}

    static constexpr Matrix2<T> zero();
    static constexpr Matrix2<T> identity();

    std::array<T, 4> val;
private:
};

 
template<typename T>
inline constexpr Matrix2<T>::Matrix2()
{
    val.fill(T(0));
}

template<typename T>
inline constexpr Matrix2<T>::Matrix2(T m11, T m12, T m21, T m22):
    val({m11, m12, m21, m22})
{
 
}
 
template<typename T>
inline constexpr Matrix2<T>::Matrix2(const std::array<T, 4>& values):
    val(values)
{
 
}
 
 
template<typename T>
inline constexpr bool Matrix2<T>::operator==(const Matrix2<T>& rhs) const
{
    return val == rhs.val;
}
 
template<typename T>
inline constexpr bool Matrix2<T>::operator!=(const Matrix2<T>& rhs) const
{
    return !(*this == rhs); 
}
 
template<typename T>
inline constexpr Matrix2<T>& Matrix2<T>::operator+=(const Matrix2<T>& rhs)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] += rhs.val[i];
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix2<T>& Matrix2<T>::operator-=(const Matrix2<T>& rhs)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] -= rhs.val[i];
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix2<T>& Matrix2<T>::operator*=(const Matrix2<T>& rhs)
{
    auto old_val = val;
    val[0] = old_val[0] * rhs.val[0] + old_val[1] * rhs.val[2];
    val[1] = old_val[0] * rhs.val[1] + old_val[1] * rhs.val[3];
    val[2] = old_val[2] * rhs.val[0] + old_val[3] * rhs.val[2];
    val[3] = old_val[2] * rhs.val[1] + old_val[3] * rhs.val[3]; 
    return *this;
}
 
template<typename T>
inline constexpr Matrix2<T>& Matrix2<T>::operator*=(T value)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] *= value;
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix2<T>& Matrix2<T>::operator/=(T value)
{
    for(auto i = 0; i < val.size(); ++i)
    {
        val[i] /= value;
    } 
    return *this;
}
 
template<typename T>
inline constexpr Matrix2<T> Matrix2<T>::operator-() const
{
    return -Matrix2<T>(-val[0], -val[1], -val[2], -val[3]); 
}

template<typename T>
inline Matrix2<T> operator+(const Matrix2<T>& lhs, const Matrix2<T>& rhs)
{
    auto tmp(lhs);
    tmp += rhs;
    return tmp;
}
 
template<typename T>
inline Matrix2<T> operator-(const Matrix2<T>& lhs, const Matrix2<T>& rhs)
{
    auto tmp(lhs);
    tmp -= rhs;
    return tmp;
}
template<typename T>
inline Matrix2<T> operator*(const Matrix2<T>& lhs, const Matrix2<T>& rhs)
{
    auto tmp(lhs);
    tmp *= rhs;
    return tmp;
}

template<typename T>
inline Matrix2<T> operator*(const Matrix2<T>& lhs, T rhs)
{
    auto tmp(lhs);
    tmp *= rhs;
    return lhs;
}

template<typename T>
inline constexpr Matrix2<T> Matrix2<T>::zero()
{
    return Matrix2<T>{0, 0, 0, 0}; 
}
 
template<typename T>
inline constexpr Matrix2<T> Matrix2<T>::identity()
{
    return Matrix2<T>{1, 0, 0, 1}; 
}
 
#endif
    

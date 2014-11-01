#ifndef GL_BOUNDSHADERPROGRAM_H__
#define GL_BOUNDSHADERPROGRAM_H__

#include "ShaderProgram.h"
#include "TargetLock.h"


#include "Vector2.h"

namespace gl
{

class BoundShaderProgram
{
public:
    BoundShaderProgram(ShaderProgram* object,
        TargetLock lock);
    ~BoundShaderProgram() = default;

    BoundShaderProgram(const BoundShaderProgram& other) = delete;
    BoundShaderProgram(BoundShaderProgram&& other) noexcept;
    BoundShaderProgram& operator =(const BoundShaderProgram& other) = delete;
    BoundShaderProgram& operator =(BoundShaderProgram&& other) noexcept;

    void set_uniform_value(int location, int value);
    void set_uniform_value(int location, unsigned int value);
    void set_uniform_value(int location, float value);
    void set_uniform_value(int location, int value1, int value2);
    void set_uniform_value(int location, unsigned int value1, unsigned int value2);
    void set_uniform_value(int location, float value1, float value2);
    void set_uniform_value(int location, int value1, int value2, int value3);
    void set_uniform_value(int location, unsigned int value1, unsigned int value2, unsigned int value3);
    void set_uniform_value(int location, float value1, float value2, float value3);
    void set_uniform_value(int location, int value1, int value2, int value3, int value4);
    void set_uniform_value(int location, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4);
    void set_uniform_value(int location, float value1, float value2, float value3, float value4);

    void set_uniform_value(int location, const Vector2i& value);
    void set_uniform_value(int location, const Vector2ui& value);
    void set_uniform_value(int location, const Vector2f& value);
    //TODO: Vector3
    //TODO: Vector4
    //TODO: Matrix2
    //TODO: Matrix3
    //TODO: Matrix4

    void set_uniform_value(const char* uniform_name, int value);
    void set_uniform_value(const char* uniform_name, unsigned int value);
    void set_uniform_value(const char* uniform_name, float value);
    void set_uniform_value(const char* uniform_name, int value1, int value2);
    void set_uniform_value(const char* uniform_name, unsigned int value1, unsigned int value2);
    void set_uniform_value(const char* uniform_name, float value1, float value2);
    void set_uniform_value(const char* uniform_name, int value1, int value2, int value3);
    void set_uniform_value(const char* uniform_name, unsigned int value1, unsigned int value2, unsigned int value3);
    void set_uniform_value(const char* uniform_name, float value1, float value2, float value3);
    void set_uniform_value(const char* uniform_name, int value1, int value2, int value3, int value4);
    void set_uniform_value(const char* uniform_name, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4);
    void set_uniform_value(const char* uniform_name, float value1, float value2, float value3, float value4);

    void set_uniform_value(const char* uniform_name, const Vector2i& value);
    void set_uniform_value(const char* uniform_name, const Vector2ui& value);
    void set_uniform_value(const char* uniform_name, const Vector2f& value);

    void set_uniform_value_matrix2(int location, const float* values, bool transpose=false);
    void set_uniform_value_matrix2(int location, const std::array<float, 4>& values, bool transpose=false);
    void set_uniform_value_matrix3(int location, const float* values, bool transpose=false);
    void set_uniform_value_matrix3(int location, const std::array<float, 9>& values, bool transpose=false);
    void set_uniform_value_matrix4(int location, const float* values, bool transpose=false);
    void set_uniform_value_matrix4(int location, const std::array<float, 16>& values, bool transpose=false);

    void set_uniform_value_matrix2(const char* uniform_name, const float* values, bool transpose=false);
    void set_uniform_value_matrix2(const char* uniform_name, const std::array<float, 4>& values, bool transpose=false);
    void set_uniform_value_matrix3(const char* uniform_name, const float* values, bool transpose=false);
    void set_uniform_value_matrix3(const char* uniform_name, const std::array<float, 9>& values, bool transpose=false);
    void set_uniform_value_matrix4(const char* uniform_name, const float* values, bool transpose=false);
    void set_uniform_value_matrix4(const char* uniform_name, const std::array<float, 16>& values, bool transpose=false);

    void set_uniform_value_array1(int location, const int* values, size_t count);
    void set_uniform_value_array1(int location, const unsigned int* values, size_t count);
    void set_uniform_value_array1(int location, const float* values, size_t count);
    template<size_t N>
    void set_uniform_value_array1(int location, const std::array<int, N>& values);
    template<size_t N>
    void set_uniform_value_array1(int location, const std::array<unsigned int, N>& values);
    template<size_t N>
    void set_uniform_value_array1(int location, const std::array<float, N>& values);

    void set_uniform_value_array2(int location, const int* values, size_t count);
    void set_uniform_value_array2(int location, const unsigned int* values, size_t count);
    void set_uniform_value_array2(int location, const float* values, size_t count);
    template<size_t N>
    void set_uniform_value_array2(int location, const std::array<int, N>& values);
    template<size_t N>
    void set_uniform_value_array2(int location, const std::array<unsigned int, N>& values);
    template<size_t N>
    void set_uniform_value_array2(int location, const std::array<float, N>& values);

    void set_uniform_value_array3(int location, const int* values, size_t count);
    void set_uniform_value_array3(int location, const unsigned int* values, size_t count);
    void set_uniform_value_array3(int location, const float* values, size_t count);
    template<size_t N>
    void set_uniform_value_array3(int location, const std::array<int, N>& values);
    template<size_t N>
    void set_uniform_value_array3(int location, const std::array<unsigned int, N>& values);
    template<size_t N>
    void set_uniform_value_array3(int location, const std::array<float, N>& values);

    void set_uniform_value_array4(int location, const int* values, size_t count);
    void set_uniform_value_array4(int location, const unsigned int* values, size_t count);
    void set_uniform_value_array4(int location, const float* values, size_t count);
    template<size_t N>
    void set_uniform_value_array4(int location, const std::array<int, N>& values);
    template<size_t N>
    void set_uniform_value_array4(int location, const std::array<unsigned int, N>& values);
    template<size_t N>
    void set_uniform_value_array4(int location, const std::array<float, N>& values);

protected:
    
    ShaderProgram* m_object = nullptr;
    TargetLock m_lock;
private:
};

inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, int value)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, unsigned int value)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, float value)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, int value1, int value2)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, unsigned int value1, unsigned int value2)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, float value1, float value2)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, int value1, int value2, int value3)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2, value3); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, unsigned int value1, unsigned int value2, unsigned int value3)
{
 
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2, value3); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, float value1, float value2, float value3)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2, value3); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, int value1, int value2, int value3, int value4)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2, value3, value4); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2, value3, value4); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, float value1, float value2, float value3, float value4)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value1, value2, value3, value4); 
}

inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, const Vector2i& value)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, const Vector2ui& value)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value); 
}
 
inline void BoundShaderProgram::set_uniform_value(const char* uniform_name, const Vector2f& value)
{
    set_uniform_value(m_object->get_uniform_location(uniform_name), value); 
}
 
inline void BoundShaderProgram::set_uniform_value_matrix2(const char* uniform_name, const float* values, bool transpose)
{
    set_uniform_value_matrix2(m_object->get_uniform_location(uniform_name), values, transpose);
}

inline void BoundShaderProgram::set_uniform_value_matrix2(const char* uniform_name, const std::array<float, 4>& values, bool transpose)
{
    set_uniform_value_matrix2(m_object->get_uniform_location(uniform_name), values, transpose);
}
 
inline void BoundShaderProgram::set_uniform_value_matrix3(const char* uniform_name, const float* values, bool transpose)
{
    set_uniform_value_matrix3(m_object->get_uniform_location(uniform_name), values, transpose);
}
 
inline void BoundShaderProgram::set_uniform_value_matrix3(const char* uniform_name, const std::array<float, 9>& values, bool transpose)
{
    set_uniform_value_matrix3(m_object->get_uniform_location(uniform_name), values, transpose);
}
 
inline void BoundShaderProgram::set_uniform_value_matrix4(const char* uniform_name, const float* values, bool transpose)
{
    set_uniform_value_matrix4(m_object->get_uniform_location(uniform_name), values, transpose);
}
 
inline void BoundShaderProgram::set_uniform_value_matrix4(const char* uniform_name, const std::array<float, 16>& values, bool transpose)
{
    set_uniform_value_matrix4(m_object->get_uniform_location(uniform_name), values, transpose);
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array1(int location, const std::array<int, N>& values)
{
    set_uniform_array1(location, values.data(), N); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array1(int location, const std::array<unsigned int, N>& values)
{
    set_uniform_array1(location, values.data(), N); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array1(int location, const std::array<float, N>& values)
{
    set_uniform_array1(location, values.data(), N); 
}
template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array2(int location, const std::array<int, N>& values)
{
    set_uniform_array2(location, values.data(), N/2); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array2(int location, const std::array<unsigned int, N>& values)
{
    set_uniform_array2(location, values.data(), N/2); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array2(int location, const std::array<float, N>& values)
{
    set_uniform_array2(location, values.data(), N/2); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array3(int location, const std::array<int, N>& values)
{
    set_uniform_array3(location, values.data(), N/3); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array3(int location, const std::array<unsigned int, N>& values)
{
    set_uniform_array3(location, values.data(), N/3); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array3(int location, const std::array<float, N>& values)
{
    set_uniform_array3(location, values.data(), N/3); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array4(int location, const std::array<int, N>& values)
{
    set_uniform_array4(location, values.data(), N/4); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array4(int location, const std::array<unsigned int, N>& values)
{
    set_uniform_array4(location, values.data(), N/4); 
}

template<size_t N>
inline void BoundShaderProgram::set_uniform_value_array4(int location, const std::array<float, N>& values)
{
    set_uniform_array4(location, values.data(), N/4); 
}
 
}
 
#endif
    

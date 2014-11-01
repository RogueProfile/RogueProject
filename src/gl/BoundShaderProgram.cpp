#include "BoundShaderProgram.h"

#include "GlMacros.h"
#include "GlException.h"

namespace gl
{

BoundShaderProgram::BoundShaderProgram(ShaderProgram* object,
        TargetLock lock):
    m_object(object), m_lock(std::move(lock))
{
}
 
BoundShaderProgram::BoundShaderProgram(BoundShaderProgram&& other) noexcept:
    m_object(std::move(other.m_object)), m_lock(std::move(other.m_lock))
{
}
 

BoundShaderProgram& BoundShaderProgram::operator=(BoundShaderProgram&& other) noexcept
{
    m_object = other.m_object;
    m_lock.release();
    m_lock = std::move(other.m_lock);
    return *this;
}

void BoundShaderProgram::set_uniform_value(int location, int value)
{
    glUniform1i(location, value);
    CHECK_GL_ERROR(glUniform1i); 
}
 
void BoundShaderProgram::set_uniform_value(int location, unsigned int value)
{
    glUniform1ui(location, value);
    CHECK_GL_ERROR(glUniform1ui); 
}
 
void BoundShaderProgram::set_uniform_value(int location, float value)
{
    glUniform1f(location, value);
    CHECK_GL_ERROR(glUniform1f); 
}
 
void BoundShaderProgram::set_uniform_value(int location, int value1, int value2)
{
    glUniform2i(location, value1, value2); 
    CHECK_GL_ERROR(glUniform2i);
}
 
void BoundShaderProgram::set_uniform_value(int location, unsigned int value1, unsigned int value2)
{
    glUniform2ui(location, value1, value2); 
    CHECK_GL_ERROR(glUniform2ui);
}
 
void BoundShaderProgram::set_uniform_value(int location, float value1, float value2)
{
    glUniform2f(location, value1, value2); 
    CHECK_GL_ERROR(glUniform2f);
}
 
void BoundShaderProgram::set_uniform_value(int location, int value1, int value2, int value3)
{
    glUniform3i(location, value1, value2, value3); 
    CHECK_GL_ERROR(glUniform3i);
}
 
void BoundShaderProgram::set_uniform_value(int location, unsigned int value1, unsigned int value2, unsigned int value3)
{
    glUniform3ui(location, value1, value2, value3); 
    CHECK_GL_ERROR(glUniform3ui);
}
 
void BoundShaderProgram::set_uniform_value(int location, float value1, float value2, float value3)
{
    glUniform3f(location, value1, value2, value3); 
    CHECK_GL_ERROR(glUniform3f);
}
 
void BoundShaderProgram::set_uniform_value(int location, int value1, int value2, int value3, int value4)
{
    glUniform4i(location, value1, value2, value3, value4); 
    CHECK_GL_ERROR(glUniform4i);
}
 
void BoundShaderProgram::set_uniform_value(int location, unsigned int value1, unsigned int value2, unsigned int value3, unsigned int value4)
{
    glUniform4ui(location, value1, value2, value3, value4); 
    CHECK_GL_ERROR(glUniform4ui);
}
 
void BoundShaderProgram::set_uniform_value(int location, float value1, float value2, float value3, float value4)
{
    glUniform4f(location, value1, value2, value3, value4); 
    CHECK_GL_ERROR(glUniform4f);
}
 
void BoundShaderProgram::set_uniform_value(int location, const Vector2i& value)
{
    glUniform2i(location, value.x, value.y); 
    CHECK_GL_ERROR(glUniform2i);
}
 
void BoundShaderProgram::set_uniform_value(int location, const Vector2ui& value)
{
    glUniform2ui(location, value.x, value.y); 
    CHECK_GL_ERROR(glUniform2ui);
}
 
void BoundShaderProgram::set_uniform_value(int location, const Vector2f& value)
{
    glUniform2f(location, value.x, value.y); 
    CHECK_GL_ERROR(glUniform2f);
}
 
void BoundShaderProgram::set_uniform_value_matrix2(int location, const float* values, bool transpose)
{
    glUniformMatrix2fv(location, 1, transpose == true ? 1 : 0, values);
    CHECK_GL_ERROR(glUniformMatrix2fv);
}
 
void BoundShaderProgram::set_uniform_value_matrix2(int location, const std::array<float, 4>& values, bool transpose)
{
    glUniformMatrix2fv(location, 1, transpose == true ? 1 : 0, values.data()); 
    CHECK_GL_ERROR(glUniformMatrix2fv);
}
 
void BoundShaderProgram::set_uniform_value_matrix3(int location, const float* values, bool transpose)
{
    glUniformMatrix3fv(location, 1, transpose == true ? 1 : 0, values);
    CHECK_GL_ERROR(glUniformMatrix3fv);
}
 
void BoundShaderProgram::set_uniform_value_matrix3(int location, const std::array<float, 9>& values, bool transpose)
{
    glUniformMatrix3fv(location, 1, transpose == true ? 1 : 0, values.data()); 
    CHECK_GL_ERROR(glUniformMatrix3fv);
}
 
void BoundShaderProgram::set_uniform_value_matrix4(int location, const float* values, bool transpose)
{
    glUniformMatrix4fv(location, 1, transpose == true ? 1 : 0, values);
    CHECK_GL_ERROR(glUniformMatrix4f);
}
 
void BoundShaderProgram::set_uniform_value_matrix4(int location, const std::array<float, 16>& values, bool transpose)
{
    glUniformMatrix4fv(location, 1, transpose == true ? 1 : 0, values.data()); 
    CHECK_GL_ERROR(glUniformMatrix4fv);
}
 
void BoundShaderProgram::set_uniform_value_array1(int location, const int* values, size_t count)
{
    glUniform1iv(location, count, values); 
    CHECK_GL_ERROR(glUniform1iv);
}
 
void BoundShaderProgram::set_uniform_value_array1(int location, const unsigned int* values, size_t count)
{
    glUniform1uiv(location, count, values); 
    CHECK_GL_ERROR(glUniform1uiv);
}
 
void BoundShaderProgram::set_uniform_value_array1(int location, const float* values, size_t count)
{
    glUniform1fv(location, count, values); 
    CHECK_GL_ERROR(glUniform1fv);
}

void BoundShaderProgram::set_uniform_value_array2(int location, const int* values, size_t count)
{
    glUniform2iv(location, count, values); 
    CHECK_GL_ERROR(glUniform2iv);
}
 
void BoundShaderProgram::set_uniform_value_array2(int location, const unsigned int* values, size_t count)
{
    glUniform2uiv(location, count, values); 
    CHECK_GL_ERROR(glUniform2uiv);
}
 
void BoundShaderProgram::set_uniform_value_array2(int location, const float* values, size_t count)
{
    glUniform2fv(location, count, values); 
    CHECK_GL_ERROR(glUniform2fv);
}
 
void BoundShaderProgram::set_uniform_value_array3(int location, const int* values, size_t count)
{
    glUniform3iv(location, count, values); 
    CHECK_GL_ERROR(glUniform3iv);
}
 
void BoundShaderProgram::set_uniform_value_array3(int location, const unsigned int* values, size_t count)
{
    glUniform3uiv(location, count, values); 
    CHECK_GL_ERROR(glUniform3uiv);
}
 
void BoundShaderProgram::set_uniform_value_array3(int location, const float* values, size_t count)
{
    glUniform3fv(location, count, values); 
    CHECK_GL_ERROR(glUniform3fv);
}
 
void BoundShaderProgram::set_uniform_value_array4(int location, const int* values, size_t count)
{
    glUniform4iv(location, count, values); 
    CHECK_GL_ERROR(glUniform4iv);
}
 
void BoundShaderProgram::set_uniform_value_array4(int location, const unsigned int* values, size_t count)
{
    glUniform4uiv(location, count, values); 
    CHECK_GL_ERROR(glUniform4uiv);
}
 
void BoundShaderProgram::set_uniform_value_array4(int location, const float* values, size_t count)
{
    glUniform4fv(location, count, values); 
    CHECK_GL_ERROR(glUniform4fv);
}
 
}
 

#include "BoundShaderProgram.h"

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

}

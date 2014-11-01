#include "BufferObject.h"

#include "GlMacros.h"
#include "GlException.h"

namespace gl
{

BufferObject::BufferObject(UsageType usage, size_t data)
{
    glGenBuffers(1, &m_handle); 
    CHECK_GL_ERROR(glGenBuffers);
}
 
BufferObject::~BufferObject()
{
    destroy(); 
}
 
BufferObject::BufferObject(BufferObject&& other) noexcept:
    GlObject(std::move(other)),
    m_usage(other.m_usage), m_size(other.m_size)
{
}
 
BufferObject& BufferObject::operator=(BufferObject&& other) noexcept
{
    destroy();
    m_handle = other.m_handle;
    other.m_handle = NullHandle;
    m_usage = other.m_usage;
    m_size = other.m_size;
    return *this;
}
 
void BufferObject::destroy()
{
    if(m_handle != NullHandle)
    {
        glDeleteBuffers(1, &m_handle);
    } 
}
 
}


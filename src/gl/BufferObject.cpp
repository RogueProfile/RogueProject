#include "BufferObject.h"

#include "GlMacros.h"
#include "GlError.h"

namespace gl
{

BufferObject::BufferObject(GlContext* ctx,
        BufferUsageType usage, size_t size, GLenum start_target):
    BufferObject(ctx, usage, nullptr, size, start_target)
{
}

BufferObject::BufferObject(GlContext* ctx, 
        BufferUsageType usage, const void* data,
    size_t size, GLenum start_target):
    m_usage(usage), m_size(size)
{
    glGenBuffers(1, &m_handle); 
    CHECK_GL_ERROR(glGenBuffers);
    allocate(data, start_target);
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
 
void BufferObject::allocate(const void* data, GLenum target)
{
    glBindBuffer(target, m_handle); 
    CHECK_GL_ERROR(glBindBuffer);
    glBufferData(target, m_size, data, static_cast<GLenum>(m_usage));
    CHECK_GL_ERROR(glBufferData);
}
 
}


#include "BoundBufferObject.h"

#include "GlMacros.h"

#include "GlException.h"

namespace gl
{

BoundBufferObject::BoundBufferObject(BufferObject* buffer, GlContext* context,
        TargetLock lock):
    m_buffer(buffer), m_context(context), m_lock(std::move(lock))
{
}
 
BoundBufferObject::BoundBufferObject(BoundBufferObject&& other) noexcept:
    m_buffer(other.m_buffer), m_context(other.m_context),
    m_lock(std::move(other.m_lock))
{
}
 
BoundBufferObject& BoundBufferObject::operator=(BoundBufferObject&& other) noexcept
{
    m_buffer = other.m_buffer;
    other.m_buffer = nullptr;
    m_context = other.m_context;
    m_lock = std::move(other.m_lock);
    return *this; 
}
 
void BoundBufferObject::set_data(const void* data)
{
    glBufferData(raw_target(), m_buffer->size(), data,
           static_cast<GLenum>(m_buffer->usage_type())); 
    CHECK_GL_ERROR(glBufferData);
}
 
void BoundBufferObject::set_data(const void* data, intptr_t offset, size_t length)
{
    glBufferSubData(raw_target(), offset, length, data);
    CHECK_GL_ERROR(glBufferSubData);
}
 
void BoundBufferObject::get_data(intptr_t offset, size_t size, char* out) const
{
    glGetBufferSubData(raw_target(), offset, size, out);
    CHECK_GL_ERROR(glGetBufferSubData); 
}
 
void BoundBufferObject::flush_mapped_buffer_range(intptr_t offset, size_t length)
{
    glFlushMappedBufferRange(raw_target(), offset, length); 
    CHECK_GL_ERROR(glFlushMappedBufferRange);
}
 
void BoundBufferObject::invalidate()
{
    glBufferData(raw_target(), m_buffer->size(), nullptr,
           static_cast<GLenum>(m_buffer->usage_type())); 
    CHECK_GL_ERROR(glBufferData);
}
 
 
void* BoundBufferObject::map_raw(intptr_t offset, size_t size, 
            const Flags<BufferObject::MappingOptions>& options,
            const Flags<BufferObject::MappingAccess>& access)
{
    auto ret = glMapBufferRange(raw_target(), offset, size,
           options.get_raw_value() | access.get_raw_value());
    CHECK_GL_ERROR(glMapBufferRange);
    return ret;
}
 
}

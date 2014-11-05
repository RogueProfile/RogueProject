#include "IndexBufferObject.h"

#include <utility>

namespace gl
{

IndexBufferObject::IndexBufferObject(BufferUsageType usage,
       size_t length, IndexFormat format):
    IndexBufferObject(usage, nullptr, length, format)
{
}
 
IndexBufferObject::IndexBufferObject(BufferUsageType usage, const void* data,
       size_t data_size, IndexFormat format):
    BufferObject(usage, data, data_size, GL_ELEMENT_ARRAY_BUFFER),
    m_format(format)
{
}
 
IndexBufferObject::IndexBufferObject(IndexBufferObject&& other) noexcept:
    BufferObject(std::move(other)),
    m_format(other.m_format)
{
 
}
 
IndexBufferObject& IndexBufferObject::operator=(IndexBufferObject&& other) noexcept
{
    destroy(); 
    m_handle = other.m_handle;
    other.m_handle = NullHandle;
    m_usage = other.m_usage;
    m_size = other.m_size;
    m_format = other.m_format;
    return *this;
}
 
}


#include "IndexBufferObject.h"

#include <utility>

namespace gl
{

IndexBufferObject::IndexBufferObject(BufferObject::UsageType usage,
       size_t element_count, IndexFormat format):
    BufferObject(usage, element_count * index_size(), GL_ELEMENT_ARRAY_BUFFER),
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
 
int IndexBufferObject::index_size() const
{
    switch(m_format)
    {
        case IndexFormat::Byte: return 1;
        case IndexFormat::UShort: return 2;
        case IndexFormat::UInt: return 4;
    } 
}
 
}


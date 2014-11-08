#include "IndexBufferObject.h"

#include <utility>

#include "GlContext.h"

namespace gl
{

IndexBufferObject::IndexBufferObject(GlContext* ctx, BufferUsageType usage,
       size_t length, IndexFormat format):
    IndexBufferObject(ctx, usage, nullptr, length, format)
{
}
 
IndexBufferObject::IndexBufferObject(GlContext* ctx, BufferUsageType usage,
       const void* data, size_t data_size, IndexFormat format):
    BufferObject(usage, data, data_size, GL_ELEMENT_ARRAY_BUFFER),
    m_format(format)
{
}
 
IndexBufferObject::IndexBufferObject(GlContext* ctx, gl::BufferUsageType usage,
       const std::vector<uint8_t>& data):
    IndexBufferObject(ctx, usage, data.data(), data.size() * sizeof(uint8_t),
            IndexFormat::UByte)
{
}
 
IndexBufferObject::IndexBufferObject(GlContext* ctx, gl::BufferUsageType usage,
       const std::vector<uint16_t>& data):
    IndexBufferObject(ctx, usage, data.data(), data.size() * sizeof(uint16_t),
        IndexFormat::UShort)
{
}
 
IndexBufferObject::IndexBufferObject(GlContext* ctx, gl::BufferUsageType usage,
       const std::vector<uint32_t>& data):
    IndexBufferObject(ctx, usage, data.data(), data.size() * sizeof(uint32_t),
        IndexFormat::UInt)
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


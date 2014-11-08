#ifndef GL_INDEXBUFFEROBJECT_H__
#define GL_INDEXBUFFEROBJECT_H__

#include <vector>
#include <array>
#include <cstdint>

#include "BufferObject.h"

#include "Enums.h"

namespace gl
{
    class GlContext;

class IndexBufferObject: public BufferObject
{
public:

    IndexBufferObject(GlContext* ctx, BufferUsageType usage, size_t length,
            IndexFormat format);
    IndexBufferObject(GlContext* ctx, BufferUsageType usage,
            const void* data, size_t element_count, IndexFormat format);
    IndexBufferObject(GlContext* ctx, BufferUsageType usage, 
          const std::vector<uint8_t>& data);  
    IndexBufferObject(GlContext* ctx, BufferUsageType usage, 
          const std::vector<uint16_t>& data);  
    IndexBufferObject(GlContext* ctx, BufferUsageType usage, 
          const std::vector<uint32_t>& data);  
    template<size_t N>
    IndexBufferObject(GlContext* ctx, BufferUsageType usage, 
          const std::array<uint8_t, N>& data); 
    template<size_t N>
    IndexBufferObject(GlContext* ctx, BufferUsageType usage, 
          const std::array<uint16_t, N>& data); 
    template<size_t N>
    IndexBufferObject(GlContext* ctx, BufferUsageType usage, 
          const std::array<uint32_t, N>& data); 

    virtual ~IndexBufferObject() = default;

    IndexBufferObject(const IndexBufferObject& other) = delete;
    IndexBufferObject(IndexBufferObject&& other) noexcept;
    IndexBufferObject& operator =(const IndexBufferObject& other) = delete;
    IndexBufferObject& operator =(IndexBufferObject&& other) noexcept;

    IndexFormat format() const {return m_format;}

    size_t index_count() const;

protected:

    IndexFormat m_format;
private:
};

inline int index_size(IndexFormat format)
{
    switch(format)
    {
        case IndexFormat::UByte: return 1;
        case IndexFormat::UShort: return 2;
        case IndexFormat::UInt: return 4;
    } 
}

inline size_t IndexBufferObject::index_count() const
{
    return m_size / index_size(m_format); 
}

template<size_t N>
inline IndexBufferObject::IndexBufferObject(gl::GlContext* ctx, gl::BufferUsageType usage,
       const std::array<uint8_t, N>& data):
    IndexBufferObject(ctx, usage, data.data(), N * sizeof(uint8_t), IndexFormat::UByte)
{
}

template<size_t N>
inline IndexBufferObject::IndexBufferObject(gl::GlContext* ctx, gl::BufferUsageType usage,
       const std::array<uint16_t, N>& data):
    IndexBufferObject(ctx, usage, data.data(), N * sizeof(uint16_t), IndexFormat::UShort)
{
}

template<size_t N>
inline IndexBufferObject::IndexBufferObject(gl::GlContext* ctx, gl::BufferUsageType usage,
       const std::array<uint32_t, N>& data):
    IndexBufferObject(ctx, usage, data.data(), N * sizeof(uint32_t), IndexFormat::UInt)
{
}
 
}

#endif
    

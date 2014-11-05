#ifndef GL_INDEXBUFFEROBJECT_H__
#define GL_INDEXBUFFEROBJECT_H__

#include "BufferObject.h"

#include "Enums.h"

namespace gl
{

class IndexBufferObject: public BufferObject
{
public:

    IndexBufferObject(BufferUsageType usage, size_t length,
            IndexFormat format);
    IndexBufferObject(BufferUsageType usage, const void* data, size_t element_count,
            IndexFormat format);
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
        case IndexFormat::Byte: return 1;
        case IndexFormat::UShort: return 2;
        case IndexFormat::UInt: return 4;
    } 
}

inline size_t IndexBufferObject::index_count() const
{
    return m_size / index_size(m_format); 
}
 
}

#endif
    

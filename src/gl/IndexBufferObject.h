#ifndef GL_INDEXBUFFEROBJECT_H__
#define GL_INDEXBUFFEROBJECT_H__

#include "BufferObject.h"

namespace gl
{

class IndexBufferObject: public BufferObject
{
public:
    enum class IndexFormat
    {
        Byte = GL_BYTE,
        UShort = GL_UNSIGNED_SHORT,
        UInt = GL_UNSIGNED_INT
    };

    IndexBufferObject(UsageType usage, size_t element_count,
            IndexFormat format);
    virtual ~IndexBufferObject() = default;

    IndexBufferObject(const IndexBufferObject& other) = delete;
    IndexBufferObject(IndexBufferObject&& other) noexcept;
    IndexBufferObject& operator =(const IndexBufferObject& other) = delete;
    IndexBufferObject& operator =(IndexBufferObject&& other) noexcept;

    IndexFormat format() const {return m_format;}

    size_t index_count() const;

protected:
    int index_size() const;

    IndexFormat m_format;
private:
};

inline size_t IndexBufferObject::index_count() const
{
    return m_size / index_size(); 
}
 
}

#endif
    

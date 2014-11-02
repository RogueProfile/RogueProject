#ifndef GL_BUFFEROBJECT_H__
#define GL_BUFFEROBJECT_H__

#include "GlObject.h"

namespace gl
{

class BufferObject: public GlObject
{
public:
    enum class UsageType
	{
		StaticDraw = GL_STATIC_DRAW,
		StaticRead = GL_STATIC_READ,
		StaticCopy = GL_STATIC_COPY,
		DynamicDraw = GL_DYNAMIC_DRAW,
		DynamicRead = GL_DYNAMIC_READ,
		DynamicCopy = GL_DYNAMIC_COPY,
		StreamDraw = GL_STREAM_DRAW,
		StreamRead = GL_STREAM_READ,
		StreamCopy = GL_STREAM_COPY
	};

	enum class MappingOptions
	{
		Flush = GL_MAP_FLUSH_EXPLICIT_BIT,
		Invalidate = GL_MAP_INVALIDATE_BUFFER_BIT,
		Unsyncronized = GL_MAP_UNSYNCHRONIZED_BIT,
		InvalidateRange = GL_MAP_INVALIDATE_RANGE_BIT
	};

    enum class MappingAccess
    {
        Read = GL_MAP_READ_BIT,
        Write = GL_MAP_WRITE_BIT
    };

    BufferObject(UsageType usage, size_t size, GLenum start_target);
    BufferObject(UsageType usage, const void* data, size_t size, GLenum start_target);
    virtual ~BufferObject();

    BufferObject(const BufferObject& other) = delete;
    BufferObject(BufferObject&& other) noexcept;
    BufferObject& operator =(const BufferObject& other) = delete;
    BufferObject& operator =(BufferObject&& other) noexcept;

    size_t size() const {return m_size;}
    UsageType usage_type() const {return m_usage;}

protected:
    virtual void destroy() override;
    void allocate(const void* data, GLenum target);

    UsageType m_usage;
    size_t m_size;
private:
};

}

#endif
    

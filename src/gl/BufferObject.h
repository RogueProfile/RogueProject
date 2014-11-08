#ifndef GL_BUFFEROBJECT_H__
#define GL_BUFFEROBJECT_H__

#include "GlObject.h"
#include "Enums.h"

namespace gl
{
class GlContext;

class BufferObject: public GlObject
{
public:

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

    BufferObject(GlContext* ctx, BufferUsageType usage, size_t size,
           GLenum start_target);
    BufferObject(GlContext* ctx, BufferUsageType usage, const void* data,
           size_t size, GLenum start_target);
    virtual ~BufferObject();

    BufferObject(const BufferObject& other) = delete;
    BufferObject(BufferObject&& other) noexcept;
    BufferObject& operator =(const BufferObject& other) = delete;
    BufferObject& operator =(BufferObject&& other) noexcept;

    size_t size() const {return m_size;}
    BufferUsageType usage_type() const {return m_usage;}

protected:
    virtual void destroy() override;
    void allocate(const void* data, GLenum target);

    BufferUsageType m_usage;
    size_t m_size;
private:
};

}

#endif
    

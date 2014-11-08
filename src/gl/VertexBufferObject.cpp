#include "VertexBufferObject.h"

#include <utility>

namespace gl
{

VertexBufferObject::VertexBufferObject(GlContext* ctx, gl::BufferUsageType usage,
        const void* data, size_t size):
    BufferObject(ctx, usage, data, size, GL_ARRAY_BUFFER)
{
}
 
VertexBufferObject::VertexBufferObject(VertexBufferObject&& other) noexcept:
    BufferObject(std::move(other))
{ 
}
 
VertexBufferObject& VertexBufferObject::operator=(VertexBufferObject&& other) noexcept
{
    BufferObject::operator=(std::move(other));
    return *this; 
}
 
}


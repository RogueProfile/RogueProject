#include "BoundVertexBufferObject.h"

namespace gl
{

BoundVertexBufferObject::BoundVertexBufferObject(BufferObject* buffer,
       GlContext* context, TargetLock lock):
    BoundBufferObject(buffer, context, std::move(lock))
{
}

BoundVertexBufferObject::BoundVertexBufferObject(BoundVertexBufferObject&& other) noexcept:
    BoundBufferObject(std::move(other))
{
 
}

BoundVertexBufferObject& BoundVertexBufferObject::operator=(BoundVertexBufferObject&& other) noexcept
{
    BoundBufferObject::operator =(std::move(other));
    return *this; 
}
 
BufferBindTarget BoundVertexBufferObject::target() const
{
    return BufferBindTarget::VertexBuffer; 
}
 
}

 
 

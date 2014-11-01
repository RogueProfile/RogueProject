#include "BoundIndexBufferObject.h"

namespace gl
{

BoundIndexBufferObject::BoundIndexBufferObject(BufferObject* buffer,
       GlContext* context, TargetLock lock):
    BoundBufferObject(buffer, context, std::move(lock))
{
}
 
BoundIndexBufferObject::BoundIndexBufferObject(BoundIndexBufferObject&& other) noexcept:
    BoundBufferObject(std::move(other))
{
}
 
BoundIndexBufferObject& BoundIndexBufferObject::operator=(BoundIndexBufferObject&& other) noexcept
{
    BoundBufferObject::operator =(std::move(other)); 
    return *this;
}
 
BufferBindTarget BoundIndexBufferObject::target() const
{
    return BufferBindTarget::IndexBuffer; 
}
 
}


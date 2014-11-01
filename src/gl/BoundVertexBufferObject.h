#ifndef GL_BOUNDVERTEXBUFFEROBJECT_H__
#define GL_BOUNDVERTEXBUFFEROBJECT_H__

#include "BoundBufferObject.h"

namespace gl
{

class BoundVertexBufferObject: public BoundBufferObject
{
public:
    BoundVertexBufferObject(BufferObject* buffer, GlContext* context,
            TargetLock lock);
    virtual ~BoundVertexBufferObject() = default;

    BoundVertexBufferObject(const BoundVertexBufferObject& other) = delete;
    BoundVertexBufferObject(BoundVertexBufferObject&& other) noexcept;
    BoundVertexBufferObject& operator =(const BoundVertexBufferObject& other) = delete;
    BoundVertexBufferObject& operator =(BoundVertexBufferObject&& other) noexcept;

protected:
    virtual BufferBindTarget target() const;

private:
};

}

#endif

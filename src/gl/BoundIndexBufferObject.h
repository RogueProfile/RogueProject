#ifndef GL_BOUNDINDEXBUFFEROBJECT_H__
#define GL_BOUNDINDEXBUFFEROBJECT_H__

#include "BoundBufferObject.h"

namespace gl
{

class BoundIndexBufferObject: public BoundBufferObject
{
public:
    BoundIndexBufferObject(BufferObject* buffer, GlContext* context,
            TargetLock lock);
    ~BoundIndexBufferObject() = default;

    BoundIndexBufferObject(const BoundIndexBufferObject& other) = delete;
    BoundIndexBufferObject(BoundIndexBufferObject&& other) noexcept;
    BoundIndexBufferObject& operator =(const BoundIndexBufferObject& other) = delete;
    BoundIndexBufferObject& operator =(BoundIndexBufferObject&& other) noexcept;

protected:
    virtual BufferBindTarget target() const;

private:
};

}

#endif
    

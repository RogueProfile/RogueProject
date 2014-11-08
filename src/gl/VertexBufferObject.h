#ifndef GL_VERTEXBUFFEROBJECT_H__
#define GL_VERTEXBUFFEROBJECT_H__

#include "BufferObject.h"

#include <vector>
#include <array>

namespace gl
{
class GlContext;

class VertexBufferObject: public BufferObject
{
public:
    VertexBufferObject(GlContext* ctx, BufferUsageType usage, size_t size);
    VertexBufferObject(GlContext* ctx, BufferUsageType usage, const void* data,
           size_t size);
    template<typename T>
    VertexBufferObject(GlContext* ctx, BufferUsageType usage, 
           const std::vector<T>& data);
    template<typename T, size_t N>
    VertexBufferObject(GlContext* ctx, BufferUsageType usage, 
           const std::array<T, N>& data);

    ~VertexBufferObject() = default;

    VertexBufferObject(const VertexBufferObject& other) = delete;
    VertexBufferObject(VertexBufferObject&& other) noexcept;
    VertexBufferObject& operator =(const VertexBufferObject& other) = delete;
    VertexBufferObject& operator =(VertexBufferObject&& other) noexcept;

protected:
private:
};

inline VertexBufferObject::VertexBufferObject(GlContext* ctx,
        BufferUsageType usage, size_t size):
    VertexBufferObject(ctx, usage, nullptr, size)
{
}

template<typename T>
VertexBufferObject::VertexBufferObject(GlContext* ctx, BufferUsageType usage,
       const std::vector<T>& data):
    VertexBufferObject(ctx, usage, data.data(), data.size() * sizeof(T))
{
}
 
template<typename T, size_t N>
VertexBufferObject::VertexBufferObject(GlContext* ctx, BufferUsageType usage,
       const std::array<T, N>& data):
    VertexBufferObject(ctx, usage, data.data(), N * sizeof(T))
{
}
 
 
}

#endif
    

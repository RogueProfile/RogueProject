#ifndef GLCONTEXT_H__
#define GLCONTEXT_H__

#include <vector>
#include <array>

#include "GlHeaders.h"

#include "Flags.h"

#include "Texture2d.h"
#include "BufferObject.h"
#include "IndexBufferObject.h"
#include "Enums.h"

namespace gl
{
class GlObject;
class ShaderProgram;
class BoundShaderProgram;
class VertexArrayObject;
class BoundVertexArrayObject;
class BoundBufferObject;

enum class ClearTarget
{
    ColorBuffer = GL_COLOR_BUFFER_BIT,
    DepthBuffer = GL_DEPTH_BUFFER_BIT,
    StencilBuffer = GL_STENCIL_BUFFER_BIT
};

class GlContext
{
public:
    GlContext() = default;
    ~GlContext() = default;

    GlContext(const GlContext& other) = delete;
    GlContext(GlContext&& other) noexcept = default;
    GlContext& operator =(const GlContext& other) = delete;
    GlContext& operator =(GlContext&& other) = default;

    void clear(const Flags<ClearTarget>& buffers);

    void draw_vertex_array(const BoundVertexArrayObject& vao, 
        PrimitiveType primitive, int first, size_t count); 

    void copy_buffer_data(const BufferObject& from, BufferObject& to,
        size_t offset_from, size_t offset_to, size_t count);

    BufferObject create_vertex_buffer(BufferObject::UsageType usage,
        size_t size);
    BufferObject create_vertex_buffer(BufferObject::UsageType usage,
        void* data, size_t data_size);
    template<typename T>
    BufferObject create_vertex_buffer(BufferObject::UsageType usage,
        const std::vector<T>& data);
    template<typename T, size_t N>
    BufferObject create_vertex_buffer(BufferObject::UsageType usage,
        const std::array<T, N>& data);

    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        size_t size, IndexFormat format);
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const void* data, size_t data_size, IndexFormat format);
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const std::vector<uint8_t>& data);
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const std::vector<uint16_t>& data);
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const std::vector<uint32_t>& data);
    template<size_t N>
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const std::array<uint8_t, N>& data);
    template<size_t N>
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const std::array<uint16_t, N>& data);
    template<size_t N>
    IndexBufferObject create_index_buffer(BufferObject::UsageType usage,
        const std::array<uint32_t, N>& data);


    VertexArrayObject create_vertex_array_object();

    BoundShaderProgram bind_shader_program(ShaderProgram& program);
    BoundBufferObject bind_buffer_object(BufferObject& buffer);
    BoundVertexArrayObject bind_vertex_array(VertexArrayObject& vao);

    Texture2d create_texture(int width, int height, int mipmap_levels,
            Texture::InternalPixelFormat format);

    void rebind_texture_2d();
    void rebind_buffer_object();
protected:

private:

    GlObject* m_bound_shader_program = nullptr;

    GlObject* m_bound_texture_2d = nullptr;

    GlObject* m_bound_buffer_object = nullptr;

    GlObject* m_bound_vertex_array = nullptr;

};

template<typename T>
inline BufferObject GlContext::create_vertex_buffer(BufferObject::UsageType usage,
    const std::vector<T>& data) 
{
    return create_vertex_buffer(usage, data.data, data.size() * sizeof(T));
}

template<typename T, size_t N>
inline BufferObject GlContext::create_vertex_buffer(BufferObject::UsageType usage,
    const std::array<T, N>& data) 
{
    return create_vertex_buffer(usage, data.data, N * sizeof(T));
}

inline IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
      const std::vector<uint8_t>& data)
{
    return create_index_buffer(usage, data.data(), data.size()*sizeof(uint8_t),
        IndexFormat::Byte); 
}
 
inline IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
      const std::vector<uint16_t>& data)
{
    return create_index_buffer(usage, data.data(), data.size()*sizeof(uint16_t),
        IndexFormat::UShort); 
}
 
inline IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
      const std::vector<uint32_t>& data)
{
    return create_index_buffer(usage, data.data(), data.size()*sizeof(uint32_t),
        IndexFormat::UInt); 
}

template<size_t N>
inline IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
    const std::array<uint8_t, N>& data)
{
    return create_index_buffer(usage, data.data(), N * sizeof(uint8_t),
        IndexFormat::Byte);
}

template<size_t N>
inline IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
    const std::array<uint16_t, N>& data)
{
    return create_index_buffer(usage, data.data(), N * sizeof(uint8_t),
        IndexFormat::UShort);
}

template<size_t N>
inline IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
    const std::array<uint32_t, N>& data)
{
    return create_index_buffer(usage, data.data(), N * sizeof(uint8_t),
        IndexFormat::UInt);
}

}

#endif
    

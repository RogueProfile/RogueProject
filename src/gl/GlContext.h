#ifndef GLCONTEXT_H__
#define GLCONTEXT_H__

#include "GlHeaders.h"

#include "Flags.h"

#include "Texture2d.h"

namespace gl
{
class GlObject;
class ShaderProgram;
class BoundShaderProgram;
class BoundVertexBufferObject;
class BufferObject;

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

    BoundShaderProgram bind_shader_program(ShaderProgram& program);
    BoundVertexBufferObject bind_vertex_buffer(BufferObject& buffer);

    Texture2d create_texture(int width, int height, int mipmap_levels,
            Texture::InternalPixelFormat format);

    void rebind_texture_2d();
    void rebind_vertex_buffer();
protected:


private:

    GlObject* m_bound_shader_program = nullptr;

    GlObject* m_bound_texture_2d = nullptr;

    GlObject* m_bound_vertex_buffer = nullptr;

};

}

#endif
    

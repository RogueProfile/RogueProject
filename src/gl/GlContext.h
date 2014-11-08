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
class TextureArray2d;
class BoundTextureArray2d;

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

    void draw_vertex_array_indexed(const BoundVertexArrayObject& vao, 
        PrimitiveType primitive, int first, size_t count);

    void copy_buffer_data(const BufferObject& from, BufferObject& to,
        size_t offset_from, size_t offset_to, size_t count);

    BoundShaderProgram bind_shader_program(ShaderProgram& program);
    BoundBufferObject bind_buffer_object(BufferObject& buffer);
    BoundVertexArrayObject bind_vertex_array(VertexArrayObject& vao);

    BoundTextureArray2d bind_texture_array_2d(TextureArray2d& texture);

    void rebind_texture_2d();
    void rebind_texture_array_2d();
    void rebind_buffer_object();
protected:

private:

    GlObject* m_bound_shader_program = nullptr;

    GlObject* m_bound_texture_2d = nullptr;
    GlObject* m_bound_texture_array_2d = nullptr;

    GlObject* m_bound_buffer_object = nullptr;

    GlObject* m_bound_vertex_array = nullptr;

};

}

#endif
    

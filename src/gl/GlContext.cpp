#include "GlContext.h"

#include "TargetBindError.h"
#include "GlError.h"

#include "GlMacros.h"
#include "BoundShaderProgram.h"
#include "BoundVertexBufferObject.h"
#include "BoundIndexBufferObject.h"
#include "Texture2d.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "BoundVertexArrayObject.h"

namespace gl
{

void GlContext::clear(const Flags<ClearTarget>& buffers)
{
    glClear(buffers.get_raw_value()); 
    CHECK_GL_ERROR(glClear);
}

BufferObject GlContext::create_vertex_buffer(BufferObject::UsageType usage, size_t size)
{
    auto buf = BufferObject(usage, size, GL_ARRAY_BUFFER); 
    rebind_vertex_buffer();
    return buf;
}
 
IndexBufferObject GlContext::create_index_buffer(BufferObject::UsageType usage,
   size_t size, IndexFormat format)
{
    auto buf = IndexBufferObject(usage, size, format); 
    return buf;
}
 
void GlContext::draw_vertex_array(const BoundVertexArrayObject& vao,
      PrimitiveType primitive, int first, size_t count)
{
    glDrawArrays(static_cast<GLenum>(primitive), first, count); 
}
 
VertexArrayObject GlContext::create_vertex_array_object()
{
    return VertexArrayObject(); 
}
 
BoundShaderProgram GlContext::bind_shader_program(ShaderProgram& program)
{
    if(m_bound_shader_program != nullptr)
    {
        throw TargetBindError(Target::ShaderProgram);
    }
    glUseProgram(program.handle());
    CHECK_GL_ERROR(glUseProgram);
    return BoundShaderProgram(&program, TargetLock(&program, 
        &m_bound_shader_program));
}
 
BoundVertexBufferObject GlContext::bind_vertex_buffer(BufferObject& buffer)
{
    if(m_bound_vertex_buffer != nullptr)
    {
        throw TargetBindError(Target::VertexBuffer);
    } 
    glBindBuffer(GL_ARRAY_BUFFER, buffer.handle());
    CHECK_GL_ERROR(glBindBuffer);
    return BoundVertexBufferObject(&buffer, this, 
            TargetLock(&buffer, &m_bound_vertex_buffer));
}
 
BoundVertexArrayObject GlContext::bind_vertex_array(VertexArrayObject& vao)
{
    if(m_bound_vertex_array != nullptr)
    {
        throw TargetBindError(Target::VertexArray);
    } 
    glBindVertexArray(vao.handle());
    CHECK_GL_ERROR(glBindVertexArray);
    return BoundVertexArrayObject(&vao, 
            TargetLock(&vao, &m_bound_vertex_array));
}
 
Texture2d GlContext::create_texture(int width, int height, int mipmap_levels, 
        Texture::InternalPixelFormat format)
{
    Texture2d texture(width, height, mipmap_levels, format);
    //Texture2d binds itself to create the texture. Restore the set
    //binding before returning back to the user.
    rebind_texture_2d();
    return texture;  
}
 
void GlContext::rebind_texture_2d()
{
    if(m_bound_texture_2d != nullptr)
    {
        glBindTexture(GL_TEXTURE_2D, m_bound_texture_2d->handle());
        CHECK_GL_ERROR(glBindTexture);
    } 
}
 
void GlContext::rebind_vertex_buffer()
{
    if(m_bound_vertex_buffer != nullptr)
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_bound_vertex_buffer->handle());
        CHECK_GL_ERROR(glBindBuffer);
    }
}
 
}

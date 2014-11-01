#include "GlContext.h"

#include "TargetBindError.h"
#include "GlException.h"

#include "GlMacros.h"
#include "BoundShaderProgram.h"
#include "BoundVertexBufferObject.h"
#include "BoundIndexBufferObject.h"
#include "Texture2d.h"

namespace gl
{

void GlContext::clear(const Flags<ClearTarget>& buffers)
{
    glClear(buffers.get_raw_value()); 
    CHECK_GL_ERROR(glClear);
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

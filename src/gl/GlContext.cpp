#include "GlContext.h"

#include "TargetBindError.h"
#include "GlError.h"

#include "GlMacros.h"
#include "BoundShaderProgram.h"
#include "TextureArray2d.h"
#include "IndexBufferObject.h"
#include "VertexArrayObject.h"
#include "BoundVertexArrayObject.h"
#include "BoundBufferObject.h"
#include "BoundTextureArray2d.h"

namespace gl
{

GlContext::GlContext()
{
}

void GlContext::clear(const Flags<ClearTarget>& buffers)
{
    glClear(buffers.get_raw_value()); 
    CHECK_GL_ERROR(glClear);
}

void GlContext::draw_vertex_array(const BoundVertexArrayObject& vao,
      PrimitiveType primitive, int first, size_t count)
{
    glDrawArrays(static_cast<GLenum>(primitive), first, count); 
    CHECK_GL_ERROR(glDrawArrays);
}

void GlContext::draw_vertex_array_indexed(const BoundVertexArrayObject& vao,
      gl::PrimitiveType primitive, int first, size_t count)
{
    glDrawElements(static_cast<GLenum>(primitive), count, 
           static_cast<GLenum>(vao.array_object().index_buffer()->format()),
           reinterpret_cast<void*>(first));
    CHECK_GL_ERROR(glDrawElements);
}
 
void GlContext::copy_buffer_data(const BufferObject& from, BufferObject& to,
       size_t offset_from, size_t offset_to, size_t count)
{
    glBindBuffer(GL_COPY_READ_BUFFER, from.handle());
    CHECK_GL_ERROR(glBindBuffer);
    glBindBuffer(GL_COPY_WRITE_BUFFER, to.handle());
    CHECK_GL_ERROR(glBindBuffer);
    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, offset_from,
        offset_to, count);
    rebind_buffer_object();
    CHECK_GL_ERROR(glCopyBufferSubData);
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
 
BoundBufferObject GlContext::bind_buffer_object(BufferObject& buffer)
{
    if(m_bound_buffer_object != nullptr)
    {
        throw TargetBindError(Target::Buffer);
    } 
    glBindBuffer(GL_COPY_WRITE_BUFFER, buffer.handle());
    CHECK_GL_ERROR(glBindBuffer);
    return BoundBufferObject(&buffer, this, 
            TargetLock(&buffer, &m_bound_buffer_object));
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
 
BoundTextureArray2d GlContext::bind_texture_array_2d(TextureArray2d& texture)
{
    if(m_bound_2d_array_textures[active_texture_unit()] != nullptr)
    {
        throw TargetBindError(Target::TextureArray2d);
    } 
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture.handle());
    CHECK_GL_ERROR(glBindTexture);
    return BoundTextureArray2d(&texture,
            TargetLock(&texture, &m_bound_2d_array_textures[active_texture_unit()]));
}
 
void GlContext::set_active_texture_unit(int unit_num)
{
    glActiveTexture(GL_TEXTURE0 + unit_num); 
    CHECK_GL_ERROR(glActiveTexture);
}
 
void GlContext::rebind_texture_2d()
{
    if(m_bound_2d_textures[active_texture_unit()] != nullptr)
    {
        glBindTexture(GL_TEXTURE_2D, 
            m_bound_2d_textures[active_texture_unit()]->handle());
        CHECK_GL_ERROR(glBindTexture);
    } 
}
 
void GlContext::rebind_texture_array_2d()
{
    if(m_bound_2d_array_textures[active_texture_unit()] != nullptr)
    {
        glBindTexture(GL_TEXTURE_2D_ARRAY, 
            m_bound_2d_array_textures[active_texture_unit()]->handle());
        CHECK_GL_ERROR(glBindTexture);
    } 
}
 
void GlContext::rebind_buffer_object()
{
    if(m_bound_buffer_object != nullptr)
    {
        glBindBuffer(GL_COPY_WRITE_BUFFER, m_bound_buffer_object->handle());
        CHECK_GL_ERROR(glBindBuffer);
    }
}
 
int GlContext::get_max_texture_units() const
{
    int out_val = 0;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &out_val);
    CHECK_GL_ERROR(glGetIntegerv);
    return out_val; 
}
 
void GlContext::initialize_bound_texture_arrays()
{
    auto max_texture_units = get_max_texture_units();
    m_bound_2d_textures.resize(max_texture_units);
    m_bound_2d_array_textures.resize(max_texture_units); 
}
 
void GlContext::initialize()
{
    initialize_bound_texture_arrays(); 
}
 
}

#include "VertexArrayObject.h"

#include <utility>

#include "GlHeaders.h"

namespace gl
{

VertexArrayObject::VertexArrayObject(gl::GlContext* ctx)
{
    glGenVertexArrays(1, &m_handle); 
}
 
VertexArrayObject::~VertexArrayObject()
{
    destroy(); 
}
 
VertexArrayObject::VertexArrayObject(VertexArrayObject&& other) noexcept:
    GlObject(std::move(other))
{
 
}
 
VertexArrayObject& VertexArrayObject::operator=(VertexArrayObject&& other) noexcept
{
    GlObject::operator=(std::move(other)); 
    return *this;
}
 
void VertexArrayObject::destroy()
{
    if(m_handle)
    {
        glDeleteVertexArrays(1, &m_handle);
    }
}
 
}


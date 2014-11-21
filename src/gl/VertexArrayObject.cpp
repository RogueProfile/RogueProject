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
    destroy();
    m_handle = NullHandle;
    std::swap(m_handle, other.m_handle);
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


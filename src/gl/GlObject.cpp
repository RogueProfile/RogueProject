#include "GlObject.h"

namespace gl
{

GlObject::GlObject(GLuint handle):
    m_handle(handle)
{
 
}
 
GlObject::GlObject(GlObject&& other) noexcept:
    m_handle(other.m_handle)
{
    other.m_handle = NullHandle; 
}
 
GlObject& GlObject::operator=(GlObject&& other) noexcept
{
    destroy();
    m_handle = other.m_handle;
    other.m_handle = NullHandle;    
    return *this;
}
 
}


#include "GlException.h"

namespace gl
{

GlException::GlException(const std::string& message, GLenum error_code):
    Exception(message),
    m_error_code(error_code)
{
}
 
GlException::GlException(const GlException& other):
    Exception(other),
    m_error_code(other.m_error_code)
{
}
 
GlException::GlException(GlException&& other) noexcept:
    Exception(std::move(other)),
    m_error_code(other.m_error_code)
{
}
 
GlException& GlException::operator=(const GlException& other)
{
    Exception::operator=(other);
    m_error_code = other.m_error_code; 
    return *this;
}
 
GlException& GlException::operator=(gl::GlException&& other) noexcept
{
    Exception::operator=(std::move(other));
    m_error_code = other.m_error_code; 
    return *this;
}
 
}


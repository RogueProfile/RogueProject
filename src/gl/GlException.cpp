#include "GlException.h"

#include "GlHeaders.h"

#include <sstream>

namespace gl
{

GlException::GlException(const std::string& function, GLenum error_code):
    m_error_code(error_code)
{
    std::ostringstream stream;
    auto error_string = gluErrorString(error_code);
    stream << "In function '" << function << "': " << error_string;
    set_message(stream.str());
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


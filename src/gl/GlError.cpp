#include "GlError.h"

#include "GlHeaders.h"

#include <sstream>

namespace gl
{

GlError::GlError(const std::string& function, GLenum error_code):
    m_error_code(error_code)
{
    std::ostringstream stream;
    auto error_string = gluErrorString(error_code);
    stream << "In function '" << function << "': " << error_string;
    set_message(stream.str());
}
 
GlError::GlError(const GlError& other):
    Exception(other),
    m_error_code(other.m_error_code)
{
}
 
GlError::GlError(GlError&& other) noexcept:
    Exception(std::move(other)),
    m_error_code(other.m_error_code)
{
}
 
GlError& GlError::operator=(const GlError& other)
{
    Exception::operator=(other);
    m_error_code = other.m_error_code; 
    return *this;
}
 
GlError& GlError::operator=(gl::GlError&& other) noexcept
{
    Exception::operator=(std::move(other));
    m_error_code = other.m_error_code; 
    return *this;
}
 
}


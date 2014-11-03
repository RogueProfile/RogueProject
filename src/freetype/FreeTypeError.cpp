#include "FreeTypeError.h"

#include <sstream>

namespace ft
{

FreeTypeError::FreeTypeError(const std::string& message, int error_code):
    m_error_code(error_code)
{
    std::ostringstream stream;
    stream << message << " error code = " << m_error_code; 
    set_message(stream.str());
}
 
FreeTypeError::FreeTypeError(const FreeTypeError& other):
    Exception(other),
    m_error_code(other.m_error_code)
{
}
 
FreeTypeError::FreeTypeError(FreeTypeError&& other) noexcept:
    Exception(std::move(other)),
    m_error_code(other.m_error_code)
{
}
 
FreeTypeError& FreeTypeError::operator=(const FreeTypeError& other)
{
    Exception::operator =(other); 
    m_error_code = other.m_error_code;
    return *this;
}
 
FreeTypeError& FreeTypeError::operator=(FreeTypeError&& other) noexcept
{
    Exception::operator =(std::move(other)); 
    m_error_code = other.m_error_code;
    return *this;
}
 
}


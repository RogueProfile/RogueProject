#include "EnumValueError.h"

#include <sstream>
 
EnumValueError::EnumValueError(std::string enum_name, std::string message):
    m_enum_name(enum_name)
{
    std::ostringstream stream;
    stream << message << ". Enum = '" << enum_name << "'"; 
    set_message(stream.str());
}
 
EnumValueError::EnumValueError(const EnumValueError& other):
    Exception(other),
    m_enum_name(other.m_enum_name)
{
 
}
 
EnumValueError::EnumValueError(EnumValueError&& other) noexcept:
    Exception(std::move(other)),
    m_enum_name(other.m_enum_name)
{
 
}
 
EnumValueError& EnumValueError::operator=(const EnumValueError& other)
{
    Exception::operator=(other);
    m_enum_name = other.m_enum_name; 
    return *this;
}
 
EnumValueError& EnumValueError::operator=(EnumValueError&& other) noexcept
{
    Exception::operator=(std::move(other));
    m_enum_name = std::move(other.m_enum_name);
    return *this;
}

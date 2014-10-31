#include "Exception.h"

#include <utility>

Exception::Exception(std::string message):
    m_message(std::move(message))
{
 
}
 
Exception::Exception(const Exception& other):
    m_message(other.m_message)
{
 
}
 
Exception::Exception(Exception&& other) noexcept:
    m_message(std::move(other.m_message))
{
 
}
 
Exception& Exception::operator=(const Exception& other)
{
    m_message = other.m_message; 
    return *this;
}
 
Exception& Exception::operator=(Exception&& other) noexcept
{
    m_message = std::move(other.m_message);
    return *this;
}
 
const char* Exception::what() const noexcept
{
    return m_message.c_str(); 
}
 
void Exception::set_message(std::string message)
{
    m_message = std::move(message); 
}
 

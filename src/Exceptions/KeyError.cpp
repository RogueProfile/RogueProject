#include "KeyError.h"

KeyError::KeyError(std::string message):
    Exception(std::move(message))
{}

KeyError::KeyError(const KeyError& other):
    Exception(other)
{
 
}

KeyError::KeyError(KeyError&& other) noexcept:
    Exception(std::move(other))
{
 
}
 
KeyError& KeyError::operator=(const KeyError& other)
{
    Exception::operator =(other);
    return *this; 
}
 
KeyError& KeyError::operator=(KeyError&& other) noexcept
{
    Exception::operator =(std::move(other));
    return *this; 
}
 
 

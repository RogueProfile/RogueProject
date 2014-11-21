#include "InvalidEventError.h"

InvalidEventError::InvalidEventError(std::string event_name):
    Exception("No event is registered with the name " + event_name)
{
 
}
 
InvalidEventError::InvalidEventError(const InvalidEventError& other):
    Exception(other)
{
 
}

InvalidEventError::InvalidEventError(InvalidEventError&& other) noexcept:
    Exception(std::move(other))
{
 
}
 
InvalidEventError& InvalidEventError::operator=(const InvalidEventError& other)
{
    Exception::operator =(other);
    return *this; 
}
 
InvalidEventError& InvalidEventError::operator=(InvalidEventError&& other) noexcept
{
    Exception::operator =(std::move(other));
    return *this; 
}


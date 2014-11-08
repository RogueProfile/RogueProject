#include "ResourceNotFoundError.h"

ResourceNotFoundError::ResourceNotFoundError(std::string message):
    Exception(std::move(message))
{
 
}

ResourceNotFoundError::ResourceNotFoundError(const ResourceNotFoundError& other):
    Exception(other)
{
 
}

ResourceNotFoundError::ResourceNotFoundError(ResourceNotFoundError&& other) noexcept:
    Exception(std::move(other))
{
 
}
 
ResourceNotFoundError& ResourceNotFoundError::operator=(const ResourceNotFoundError& other)
{
    Exception::operator =(other);
    return *this; 
}
 
ResourceNotFoundError& ResourceNotFoundError::operator=(ResourceNotFoundError&& other) noexcept
{
    Exception::operator =(std::move(other));
    return *this; 
}
 
 
 

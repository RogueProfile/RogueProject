#ifndef RESOURCENOTFOUNDERROR_H__
#define RESOURCENOTFOUNDERROR_H__

#include "Exception.h"

class ResourceNotFoundError: public Exception
{
public:
    ResourceNotFoundError(std::string message);
    ~ResourceNotFoundError() = default;

    ResourceNotFoundError(const ResourceNotFoundError& other);
    ResourceNotFoundError(ResourceNotFoundError&& other) noexcept;
    ResourceNotFoundError& operator =(const ResourceNotFoundError& other);
    ResourceNotFoundError& operator =(ResourceNotFoundError&& other) noexcept;

protected:
private:
};


#endif
    

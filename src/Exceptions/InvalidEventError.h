#ifndef INVALIDEVENTERROR_H__
#define INVALIDEVENTERROR_H__

#include "Exception.h"

class InvalidEventError: public Exception
{
public:
    InvalidEventError(std::string event_name);
    ~InvalidEventError() = default;

    InvalidEventError(const InvalidEventError& other);
    InvalidEventError(InvalidEventError&& other) noexcept;
    InvalidEventError& operator =(const InvalidEventError& other);
    InvalidEventError& operator =(InvalidEventError&& other) noexcept;

protected:
private:
};


#endif
    

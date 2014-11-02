#ifndef KEYERROR_H__
#define KEYERROR_H__

#include "Exception.h"

class KeyError: public Exception
{
public:
    KeyError(std::string message);
    ~KeyError() = default;

    KeyError(const KeyError& other);
    KeyError(KeyError&& other) noexcept;
    KeyError& operator =(const KeyError& other);
    KeyError& operator =(KeyError&& other) noexcept;

protected:
private:
};


#endif
    

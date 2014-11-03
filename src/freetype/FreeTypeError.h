#ifndef FT_FREETYPEERROR_H__
#define FT_FREETYPEERROR_H__

#include "Exceptions/Exception.h"

#include "Exception.h"

#include <string>

namespace ft
{

class FreeTypeError: public Exception
{
public:
    FreeTypeError(const std::string& message, int error_code);
    ~FreeTypeError() = default;

    FreeTypeError(const FreeTypeError& other);
    FreeTypeError(FreeTypeError&& other) noexcept;
    FreeTypeError& operator =(const FreeTypeError& other);
    FreeTypeError& operator =(FreeTypeError&& other) noexcept;

protected:
    int m_error_code;
private:
};

}

#endif
    

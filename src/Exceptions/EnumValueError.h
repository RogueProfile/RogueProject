#ifndef ENUMVALUEERROR_H__
#define ENUMVALUEERROR_H__

#include "Exception.h"

class EnumValueError: public Exception
{
public:
    EnumValueError(std::string enum_name, std::string message);
    virtual ~EnumValueError() = default;

    EnumValueError(const EnumValueError& other);
    EnumValueError(EnumValueError&& other) noexcept;
    EnumValueError& operator =(const EnumValueError& other);
    EnumValueError& operator =(EnumValueError&& other) noexcept;

    const std::string& enum_name() const {return m_enum_name;}

protected:
    std::string m_enum_name;
private:
};


#endif
    

#ifndef EXCEPTION_H__
#define EXCEPTION_H__

#include <string>
#include <exception>

class Exception: public std::exception
{
public:
    Exception(std::string message);
    virtual ~Exception() = default;

    Exception(const Exception& other);
    Exception(Exception&& other) noexcept;
    Exception& operator =(const Exception& other);
    Exception& operator =(Exception&& other) noexcept;

    virtual const char* what() const noexcept override;

protected:
    void set_message(std::string message);

    std::string m_message;
};

#endif
    

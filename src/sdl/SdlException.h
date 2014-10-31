#ifndef SDL_SDLEXCEPTION_H__
#define SDL_SDLEXCEPTION_H__

#include "Exceptions/Exception.h"

namespace sdl
{

class SdlException : public Exception
{
public:
    SdlException(std::string sdl_error);
    virtual ~SdlException() = default;

    SdlException(const SdlException& other) = default;
    SdlException(SdlException&& other) noexcept = default;
    SdlException& operator =(const SdlException& other) = default;
    SdlException& operator =(SdlException&& other) noexcept = default;

protected:
private:
};

}

#endif
    

#include "SdlException.h"

namespace sdl
{

SdlException::SdlException(std::string sdl_error):
    Exception(std::move(sdl_error))
{
 
}
 
}


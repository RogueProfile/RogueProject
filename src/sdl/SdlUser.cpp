#include "SdlUser.h"

#include "sdl/SdlException.h"

namespace sdl
{

SdlUser::SdlUser(Flags<SdlSubsystem> init_subsystems)
{
    if(SDL_Init(init_subsystems.get_raw_value()) != 0)
    {
        throw SdlException(SDL_GetError());
    }
}
 
SdlUser::~SdlUser()
{
    SDL_Quit(); 
}
 
}

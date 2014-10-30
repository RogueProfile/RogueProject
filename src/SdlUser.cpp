#include "SdlUser.h"


SdlUser::SdlUser(Flags<SdlUser::SdlSubsystem> init_subsystems)
{
    SDL_Init(init_subsystems.get_raw_value()); 
}
 
SdlUser::~SdlUser()
{
    SDL_Quit(); 
}
 

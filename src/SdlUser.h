#ifndef SDLUSER_H__
#define SDLUSER_H__

#include <SDL2/SDL.h>

#include "Flags.h"

enum class SdlSubsystem
{
    Timer = SDL_INIT_TIMER,
    Audio = SDL_INIT_AUDIO,
    Video = SDL_INIT_VIDEO,
    Joystick = SDL_INIT_JOYSTICK,
    Haptic = SDL_INIT_HAPTIC,
    GameController = SDL_INIT_GAMECONTROLLER,
    Events = SDL_INIT_EVENTS
};

class SdlUser
{
public:

    explicit SdlUser(Flags<SdlSubsystem> init_subsystems);
    ~SdlUser();

    SdlUser(const SdlUser& other) = delete;
    SdlUser(SdlUser&& other) noexcept = default;
    SdlUser& operator =(const SdlUser& other) = delete;
    SdlUser& operator =(SdlUser&& other) noexcept = default;

protected:
private:
};


#endif
    

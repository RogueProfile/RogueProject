#ifndef SDLWINDOW_H__
#define SDLWINDOW_H__

#include <string>
#include <memory>

#include <SDL2/SDL.h>

#include "Flags.h"
#include "Vector2.h"

namespace event
{
class Event;
}

namespace sdl
{

class SdlWindow
{
public:
    enum class WindowFlags 
    {
        Resizable = SDL_WINDOW_RESIZABLE,
        OpenGl = SDL_WINDOW_OPENGL,
        Fullscreen = SDL_WINDOW_FULLSCREEN,
        FullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP
    };
    SdlWindow(const std::string& title, int width, int height,
            const Flags<WindowFlags>& flags);
    ~SdlWindow();

    SdlWindow(const SdlWindow& other) = delete;
    SdlWindow(SdlWindow&& other) noexcept;
    SdlWindow& operator =(const SdlWindow& other) = delete;
    SdlWindow& operator =(SdlWindow&& other) noexcept;

    Vector2i size() const; 
    void resize(const Vector2i& new_size);

    Vector2i position() const;
    void set_position(const Vector2i& new_position);

    std::string title() const;
    void set_title(const std::string& title);

    void swap_window();

    std::unique_ptr<event::Event> poll_event();

    SDL_Window* get_handle() const {return m_handle;}

protected:
    void destroy();

    std::unique_ptr<event::Event> translate_event(const SDL_Event& event);

    SDL_Window* m_handle;
};

}

#endif
    

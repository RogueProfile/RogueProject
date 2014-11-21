#include "SdlWindow.h"

#include "Events/WindowEvent.h"
#include "Events/KeyboardEvent.h"

#include "SdlException.h"

namespace sdl
{

SdlWindow::SdlWindow(const std::string& title, int width, int height,
        const Flags<SdlWindow::WindowFlags>& flags)
{
    m_handle = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
           SDL_WINDOWPOS_UNDEFINED, width, height, flags.get_raw_value()); 
    if(m_handle == nullptr)
    {
        std::string error_msg = SDL_GetError();
        throw SdlException(std::move(error_msg));
    }
}
 
SdlWindow::~SdlWindow()
{
    destroy();
}
 
Vector2i SdlWindow::size() const
{
    Vector2i size;
    SDL_GetWindowSize(m_handle, &size.x, &size.y);
    return size; 
}
 
void SdlWindow::resize(const Vector2i& new_size)
{
    SDL_SetWindowSize(m_handle, new_size.x, new_size.y); 
}
 
Vector2i SdlWindow::position() const
{
    Vector2i position;
    SDL_GetWindowPosition(m_handle, &position.x, &position.y); 
    return position;
}
 
void SdlWindow::set_position(const Vector2i& new_position)
{
    SDL_SetWindowPosition(m_handle, new_position.x, new_position.y);
}
 
std::string SdlWindow::title() const
{
    return std::string(SDL_GetWindowTitle(m_handle)); 
}
 
void SdlWindow::set_title(const std::string& title)
{
    SDL_SetWindowTitle(m_handle, title.c_str()); 
}
 
void SdlWindow::swap_window()
{
    SDL_GL_SwapWindow(m_handle); 
}
 
SdlWindow::SdlWindow(SdlWindow&& other) noexcept:
    m_handle(other.m_handle)
{
    other.m_handle = nullptr; 
}
 
SdlWindow& SdlWindow::operator=(SdlWindow&& other) noexcept
{
    destroy();
    m_handle = other.m_handle;
    other.m_handle = nullptr;
    return *this;
}
 
std::unique_ptr<event::WindowEvent> SdlWindow::poll_event()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        return translate_event(event);
    }
    return nullptr;
}
 
void SdlWindow::destroy()
{
 
    if(m_handle != nullptr)
    {
        SDL_DestroyWindow(m_handle);
        m_handle = nullptr;
    } 
}
 
std::unique_ptr<event::WindowEvent> SdlWindow::translate_event(const SDL_Event& event)
{
    switch(event.type)
    {
        case SDL_QUIT: return std::make_unique<event::WindowEvent>(event::EventType::Quit);
        case SDL_KEYDOWN: return std::make_unique<event::KeyboardEvent>(event::EventType::KeyDown, 
            reinterpret_cast<const SDL_KeyboardEvent&>(event));
        case SDL_KEYUP: return std::make_unique<event::KeyboardEvent>(event::EventType::KeyUp, 
            reinterpret_cast<const SDL_KeyboardEvent&>(event));
        default:
        {
            return std::make_unique<event::WindowEvent>(event::EventType::Unknown);
        }
    } 
}

}
 

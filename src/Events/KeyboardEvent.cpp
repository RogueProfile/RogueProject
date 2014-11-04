#include "KeyboardEvent.h"

namespace event
{

KeyboardEvent::KeyboardEvent(event::EventType type, const SDL_KeyboardEvent& sdl_event):
    Event(type),
    m_mod_keys(Flags<ModKey>(static_cast<ModKey>(sdl_event.keysym.mod))),
    m_scan_code(static_cast<ScanCode>(sdl_event.keysym.scancode)), 
    m_key_code(static_cast<KeyCode>(sdl_event.keysym.sym)),
    m_key_state(static_cast<KeyState>(sdl_event.state)), m_is_repeat(sdl_event.repeat != 0)
{
}
 
}


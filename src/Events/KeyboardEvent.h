#ifndef EVENT_KEYBOARDEVENT_H__
#define EVENT_KEYBOARDEVENT_H__

#include "WindowEvent.h"

#include <SDL2/SDL.h>

#include "KeyboardState.h"
#include "Flags.h"

namespace event
{

class KeyboardEvent: public WindowEvent, public VisitableImpl<KeyboardEvent, EventVisitor>
{
public:
    KeyboardEvent(EventType type, const SDL_KeyboardEvent& event);
    virtual ~KeyboardEvent() = default;

    KeyboardEvent(const KeyboardEvent& other) = default;
    KeyboardEvent(KeyboardEvent&& other) noexcept = default;
    KeyboardEvent& operator =(const KeyboardEvent& other) = default;
    KeyboardEvent& operator =(KeyboardEvent&& other) noexcept = default;

    Flags<ModKey> mod_keys() const {return m_mod_keys;}
    ScanCode scan_code() const {return m_scan_code;}
    KeyCode key_code() const {return m_key_code;}
    KeyState key_state() const {return m_key_state;}
    bool is_repeat() const {return m_is_repeat;}

protected:
    Flags<ModKey> m_mod_keys;
    ScanCode m_scan_code;
    KeyCode m_key_code;
    KeyState m_key_state;
    bool m_is_repeat;
private:
};

}

#endif
    

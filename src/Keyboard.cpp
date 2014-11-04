#include "Keyboard.h"

KeyboardState Keyboard::m_current_state = KeyboardState();
KeyboardState Keyboard::m_last_state = KeyboardState();
 
void Keyboard::update()
{
    m_last_state = m_current_state;
    int num_keys = 0;
    auto key_state = SDL_GetKeyboardState(&num_keys);
    for(auto i = 0; i < num_keys; ++i)
    {
        m_current_state.m_scan_codes[i] = key_state[i];
    }
    m_current_state.m_mod_keys = Flags<ModKey>(
        static_cast<ModKey>(SDL_GetModState()));
}

void Keyboard::initialize()
{
    update();
    update(); 
}
 

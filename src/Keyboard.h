#ifndef KEYBOARD_H__
#define KEYBOARD_H__

#include "KeyboardState.h"

class Keyboard
{
    friend class Game;
public:
    ~Keyboard() = default;

    Keyboard(const Keyboard& other) = delete;
    Keyboard(Keyboard&& other) noexcept = delete;
    Keyboard& operator =(const Keyboard& other) = delete;
    Keyboard& operator =(Keyboard&& other) noexcept = delete;

    static const KeyboardState& current_state() {return m_current_state;}
    static const KeyboardState& last_state() {return m_last_state;}

protected:
    static KeyboardState m_current_state;
    static KeyboardState m_last_state;

    static void update();
    static void initialize();

    Keyboard();
private:
};


#endif
    

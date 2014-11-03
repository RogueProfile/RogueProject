#include "KeyboardState.h"

KeyboardState::KeyboardState(const KeyboardState& other):
    m_scan_codes(other.m_scan_codes), m_mod_keys(other.m_mod_keys)
{
 
}

KeyboardState::KeyboardState(KeyboardState&& other) noexcept:
    m_scan_codes(std::move(other.m_scan_codes)), m_mod_keys(other.m_mod_keys)
{
 
}
 
KeyboardState& KeyboardState::operator=(const KeyboardState& other)
{
    m_scan_codes = other.m_scan_codes;
    m_mod_keys = other.m_mod_keys; 
    return *this;
}
 
KeyboardState& KeyboardState::operator=(KeyboardState&& other) noexcept
{
    m_scan_codes = std::move(other.m_scan_codes);
    m_mod_keys = other.m_mod_keys; 
    return *this;
}
 
 

#include "InputTranslator.h"

InputTranslator::InputTranslator(InputTranslator&& other) noexcept:
    m_binding_map(std::move(other.m_binding_map))
{
 
}
 
InputTranslator& InputTranslator::operator=(InputTranslator&& other) noexcept
{
    m_binding_map = std::move(other.m_binding_map); 
    return *this;
}
 
void InputTranslator::bind_event(const Event& event, KeyCode key_code,
        Flags<InputTranslator::Modifier> modifiers)
{
    m_binding_map[KeyBinding{key_code, modifiers}] = &event;
}

void InputTranslator::unbind(KeyCode key_code, Flags<InputTranslator::Modifier> modifiers)
{
    auto it = m_binding_map.find(KeyBinding{key_code, modifiers}); 
    if(it != m_binding_map.end())
    {
        m_binding_map.erase(it);
    }
}

const Event* InputTranslator::translate_input(const event::KeyboardEvent& input) const
{
    Flags<Modifier> mods;
    auto mod_keys = input.mod_keys();
    if(mod_keys.has_flag(ModKey::LShift) || mod_keys.has_flag(ModKey::RShift))
    {
        mods.set_flag(Modifier::Shift);
    }
    if(mod_keys.has_flag(ModKey::LControl) || mod_keys.has_flag(ModKey::RControl))
    {
        mods.set_flag(Modifier::Ctrl);
    }
    if(mod_keys.has_flag(ModKey::LAlt) || mod_keys.has_flag(ModKey::RAlt))
    {
        mods.set_flag(Modifier::Alt);
    }

    auto it = m_binding_map.find(KeyBinding{input.key_code(), mods});
    if(it != m_binding_map.end())
    {
        return it->second;
    }
    return nullptr;
}
 
const Event* InputTranslator::get_bound_event(KeyCode key_code,
       Flags<InputTranslator::Modifier> modifiers) const
{
    auto it = m_binding_map.find(KeyBinding{key_code, modifiers});
    if(it != m_binding_map.end())
    {
        return it->second;
    } 
    return nullptr;
}
 

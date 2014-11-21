#ifndef INPUTTRANSLATOR_H__
#define INPUTTRANSLATOR_H__

#include <unordered_map>

#include "KeyboardState.h"
#include "Flags.h"
#include "Event.h"

#include "Events/KeyboardEvent.h"

class InputTranslator
{
public:
    enum class Modifier
    {
        Alt = 1,
        Shift = 2,
        Ctrl = 4
    };

    struct KeyBinding
    {
        bool operator ==(const KeyBinding& other) const
        {
            return code == other.code && modifiers == other.modifiers;
        }

        bool operator !=(const KeyBinding& other) const
        {
            return !(*this != other);
        }

        KeyCode code;
        Flags<Modifier> modifiers;
    };

    struct KeyBindingHasher
    {
        size_t operator ()(const KeyBinding& binding) const
        {
            auto hash = std::hash<std::underlying_type<KeyCode>::type>()(
                    static_cast<std::underlying_type<KeyCode>::type>(binding.code));
            hash ^= std::hash<Flags<Modifier>::StorageType>()(binding.modifiers.get_raw_value()) << 24;
            return hash;
        }
    };

    using MapType = std::unordered_map<KeyBinding, const Event*, KeyBindingHasher>;

    InputTranslator() = default;
    ~InputTranslator() = default;

    InputTranslator(const InputTranslator& other) = delete;
    InputTranslator(InputTranslator&& other) noexcept;
    InputTranslator& operator =(const InputTranslator& other) = delete;
    InputTranslator& operator =(InputTranslator&& other) noexcept;

    void bind_event(const Event& event, KeyCode key_code,
            Flags<Modifier> modifiers);
    void bind_event(const Event& event, char32_t key,
            Flags<Modifier> modifiers)
    {
        bind_event(event, char32_to_key_code(key), modifiers);
    }

    void unbind(KeyCode key_code, Flags<Modifier> modifiers);
    void unbind(char32_t key, Flags<Modifier> modifiers)
    {
        unbind(char32_to_key_code(key), modifiers);
    }

    const Event* translate_input(const event::KeyboardEvent& input) const;

    const Event* get_bound_event(KeyCode key_code, Flags<Modifier> modifiers) const;
    const Event* get_bound_event(char32_t key_code, Flags<Modifier> modifiers) const
    {
        return get_bound_event(char32_to_key_code(key_code), modifiers);
    }

    bool is_bound(KeyCode key_code, Flags<Modifier> modifiers) const
    {
        return get_bound_event(key_code, modifiers) != nullptr;
    }
    bool is_bound(char32_t key_code, Flags<Modifier> modifiers) const
    {
        return is_bound(char32_to_key_code(key_code), modifiers);
    }


protected:
    static constexpr KeyCode char32_to_key_code(char32_t key) 
        {return static_cast<KeyCode>(key);}

    MapType m_binding_map; 
    
private:
};

#endif
    

#include "ScreenManager.h"

#include "Screen.h"

#include "Exceptions/KeyError.h"


ScreenManager::~ScreenManager()
{
 
}
 
ScreenManager::ScreenManager(ScreenManager&& other) noexcept:
    m_screens(std::move(other.m_screens)), m_active_screen(other.m_active_screen)    
{
    other.m_active_screen = nullptr; 
}
 
ScreenManager& ScreenManager::operator=(ScreenManager&& other) noexcept
{
    m_screens = std::move(other.m_screens);
    m_active_screen = other.m_active_screen; 
    other.m_active_screen = nullptr;
    return *this;
}
 
void ScreenManager::add_screen(std::unique_ptr<Screen> screen, std::string name)
{
    auto it = m_screens.find(name);
    if(it != m_screens.end())
    {
        throw KeyError("Screen '" + name + "' is already defined");
    }    
    auto raw_screen = screen.get(); 
    m_screens.insert(std::make_pair(std::move(name), std::move(screen)));
    if(m_active_screen == nullptr)
    {
        m_active_screen = raw_screen;
        m_active_screen->on_activate();
    }
}
 
Screen* ScreenManager::get_screen(const std::string& name)
{
    auto it = m_screens.find(name);
    if(it == m_screens.end())
    {
        throw KeyError("Screen '" + name + "' is not defined");
    } 
    return it->second.get();
}
 
void ScreenManager::remove_screen(const std::string& name)
{
    auto it = m_screens.find(name);
    if(it == m_screens.end())
    {
        throw KeyError("Screen '" + name + "' is not defined");
    }
    if(it->second.get() == m_active_screen)
    {
        m_active_screen = nullptr;
    }
    m_screens.erase(it);
}
 
bool ScreenManager::has_screen(const std::string& name) const
{
    return m_screens.find(name) != m_screens.end(); 
}
 
void ScreenManager::activate_screen(const std::string& name)
{
    auto screen = get_screen(name);
    if(screen != m_active_screen)
    {
        m_active_screen->on_deactivate();
        m_active_screen = screen; 
        m_active_screen->on_activate();
    }
}
 
void ScreenManager::update()
{
    for(auto& screen : m_screens)
    {
        screen.second->update();
    }
}
 
void ScreenManager::draw()
{
    if(m_active_screen)
    {
        m_active_screen->draw();
    }     
}
 

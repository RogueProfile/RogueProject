#ifndef SCREENMANAGER_H__
#define SCREENMANAGER_H__

#include <vector>
#include <memory>
#include <unordered_map>
#include <string>

class Screen;

class ScreenManager
{
public:
    ScreenManager() = default;
    ~ScreenManager();

    ScreenManager(const ScreenManager& other) = delete;
    ScreenManager(ScreenManager&& other) noexcept;
    ScreenManager& operator =(const ScreenManager& other) = delete;
    ScreenManager& operator =(ScreenManager&& other) noexcept;

    void add_screen(std::unique_ptr<Screen> screen, std::string name);
    Screen* get_screen(const std::string& name);

    void remove_screen(const std::string& name);

    bool has_screen(const std::string& name) const;

    void activate_screen(const std::string& name);

    Screen* active_screen() const {return m_active_screen;}

    void update();
    void draw();

protected:
    std::unordered_map<std::string, std::unique_ptr<Screen>> m_screens;
    Screen* m_active_screen = nullptr;
private:
};


#endif
    

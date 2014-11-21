#ifndef SCREEN_H__
#define SCREEN_H__

#include "Events/WindowEvent.h"

class ScreenManager;

class Screen: public event::EventVisitor
{
    friend class ScreenManager;
public:
    Screen(ScreenManager* manager);
    virtual ~Screen() = default;

    Screen(const Screen& other) = delete;
    Screen(Screen&& other) noexcept = delete;
    Screen& operator =(const Screen& other) = delete;
    Screen& operator =(Screen&& other) noexcept = delete;

protected:
    virtual void update() = 0;
    virtual void draw() = 0;

    virtual void on_activate() {}
    virtual void on_deactivate() {}

    ScreenManager* m_manager;
private:
};


#endif
    

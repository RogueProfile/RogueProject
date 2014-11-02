#ifndef SCREEN_H__
#define SCREEN_H__

class ScreenManager;

class Screen
{
    friend class ScreenManager;
public:
    Screen(ScreenManager* manager);
    ~Screen() = default;

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
    

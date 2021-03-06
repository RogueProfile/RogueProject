#ifndef GAME_H__
#define GAME_H__

#include <chrono>

#include "sdl/SdlUser.h"
#include "sdl/SdlWindow.h"
#include "sdl/SdlGlContext.h"

#include "ScreenManager.h"

#include "Vector2.h"

namespace ft
{
    class FontManager;
}

class TileSet;
class EventManager;

class Game: public sdl::SdlUser
{
public:
    using Clock = std::chrono::high_resolution_clock;
    Game(Vector2i window_size);
    ~Game();

    Game(const Game& other) = delete;
    Game(Game&& other) noexcept = delete;
    Game& operator =(const Game& other) = delete;
    Game& operator =(Game&& other) noexcept = delete;

    void run();

protected:
    void initialize();
    void initialize_screens();
    void initialize_tile_set();
    void initialize_open_gl();

    void update();
    void draw();

    ScreenManager m_screen_manager;
    sdl::SdlWindow m_window;
    std::unique_ptr<sdl::SdlGlContext> m_context;

    std::unique_ptr<ft::FontManager> m_font_manager;
    std::unique_ptr<TileSet> m_tile_set;

    std::unique_ptr<EventManager> m_event_manager;
    
    Clock::time_point m_frame_start_time;

    double m_target_framerate = 60.0;
    bool m_is_running = false;
private:
};


#endif

#ifndef GAME_H__
#define GAME_H__

#include "sdl/SdlUser.h"
#include "sdl/SdlWindow.h"
#include "sdl/SdlGlContext.h"

#include "Vector2.h"

class Game: public sdl::SdlUser
{
public:
    Game(Vector2i window_size);
    ~Game() = default;

    Game(const Game& other) = delete;
    Game(Game&& other) noexcept = delete;
    Game& operator =(const Game& other) = delete;
    Game& operator =(Game&& other) noexcept = delete;

    void run();

protected:
    void initialize();
    void initialize_open_gl();

    sdl::SdlWindow m_window;
    std::unique_ptr<sdl::SdlGlContext> m_context;
private:
};


#endif
    

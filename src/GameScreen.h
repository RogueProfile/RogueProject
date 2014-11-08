#ifndef GAMESCREEN_H__
#define GAMESCREEN_H__

#include "Screen.h"

#include <memory>

namespace gl
{
    class GlContext;
}

class TileSet;
class TileGrid;
class TileGridRenderer;

class GameScreen: public Screen
{
public:
    GameScreen(ScreenManager* manager, gl::GlContext* context,
        TileSet* tile_set);
    virtual ~GameScreen();

    GameScreen(const GameScreen& other) = delete;
    GameScreen(GameScreen&& other) noexcept = delete;
    GameScreen& operator =(const GameScreen& other) = delete;
    GameScreen& operator =(GameScreen&& other) noexcept = delete;


protected:
    virtual void update() override;
    virtual void draw() override;

    void initialize_renderer();

    TileSet* m_tile_set;
    std::unique_ptr<TileGrid> m_tile_grid;
    std::unique_ptr<TileGridRenderer> m_renderer;

    gl::GlContext* m_context;
private:
};


#endif

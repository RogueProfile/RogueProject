#include "GameScreen.h"

#include "ScreenManager.h"

#include "gl/GlContext.h"

#include "TileGrid.h"
#include "TileSet.h"
#include "TileGridRenderer.h"
#include "Matrix3.h"


GameScreen::GameScreen(ScreenManager* manager, gl::GlContext* context,
        TileSet* tile_set):
    Screen(manager),
    m_context(context), m_tile_set(tile_set),
    m_tile_grid(new TileGrid(10, 10))
{
    initialize_renderer();
}

GameScreen::~GameScreen()
{
 
}

void GameScreen::draw()
{
    m_renderer->render(); 
}
 
 
void GameScreen::update()
{
 
}
 
void GameScreen::initialize_renderer()
{
    auto shader_prog = TileGridRenderer::create_default_shader(m_context);
    auto projection = Matrix3f::make_orthographic_projection(0, 800, 600, 0);
    m_renderer = std::make_unique<TileGridRenderer>(m_context,
        std::move(shader_prog), projection, m_tile_set, m_tile_grid.get()); 
}
 

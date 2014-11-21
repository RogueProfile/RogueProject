#include "Game.h"

#include <thread>
#include <chrono>
#include <iostream>
#include <stdexcept>

#include "Events/WindowEvent.h"

#include "freetype/FontManager.h"
#include "freetype/FontFace.h"

#include "GlHeaders.h"
#include "GameScreen.h"
#include "TextTileSet.h"

#include "Screen.h"
#include "Keyboard.h"

Game::Game(Vector2i window_size):
    sdl::SdlUser({sdl::SdlSubsystem::Video, sdl::SdlSubsystem::Events}),
    m_window("Roguelike", window_size.x, window_size.y, sdl::SdlWindow::WindowFlags::OpenGl),
    m_font_manager(std::make_unique<ft::FontManager>("assets/fonts"))
{
    initialize();
}
 
Game::~Game()
{
}
 
void Game::run()
{
    m_is_running = true;
    while(m_is_running)
    {
        m_frame_start_time = Clock::now();
        for(auto event = m_window.poll_event(); event != nullptr; event = m_window.poll_event())
        {
            if(event->type() == event::EventType::Quit)
            {
                return;
            }
            else
            {
            }
        }
        Keyboard::update();
        m_context->clear({gl::ClearTarget::ColorBuffer, gl::ClearTarget::DepthBuffer,
            gl::ClearTarget::StencilBuffer}); 

        update();
        draw();

        m_window.swap_window();

        auto frame_duration = std::chrono::duration_cast<std::chrono::duration<double, std::micro>>
            (Clock::now() - m_frame_start_time);

        if(m_target_framerate > 0)
        {
            auto sleep_time = (1000000.0 / m_target_framerate) - frame_duration.count();
            if(sleep_time > 0)
            {
                std::this_thread::sleep_for(std::chrono::microseconds(static_cast<uint32_t>(sleep_time)));
            }
        }
    }
} 
void Game::initialize()
{
    initialize_open_gl(); 
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        throw std::runtime_error("GLEW could not be initialized");
    }
    glGetError();
    Keyboard::initialize();
    initialize_tile_set();
    initialize_screens();
}
 
void Game::initialize_screens()
{
    m_screen_manager.add_screen(std::make_unique<GameScreen>(
        &m_screen_manager, m_context.get(), m_tile_set.get()), "game_screen");
}
 
void Game::initialize_tile_set()
{
    auto tile_font = m_font_manager->get_font_face("DejaVuSansMono",
        0, 12, ft::GlyphLoadFlags::Render, 0);
    m_tile_set = std::make_unique<TextTileSet>(m_context.get(),
            std::move(tile_font), 2000);
}
 
void Game::initialize_open_gl()
{
    sdl::SdlGlContext::ContextSettings settings;
    settings.major_version = 3;
    settings.minor_version = 1;
    settings.vsync = false;    
    settings.red_depth = 8;
    settings.green_depth = 8;
    settings.blue_depth = 8;
    settings.alpha_depth = 8;
    settings.depth_buffer_size = 24;
    settings.stencil_buffer_size = 8;
    settings.double_buffer = true;

    m_context = std::make_unique<sdl::SdlGlContext>(m_window, settings);
}
 
void Game::update()
{
    m_screen_manager.update(); 
}
 
void Game::draw()
{
    m_screen_manager.draw(); 
}
 

#include "Game.h"

#include <thread>
#include <chrono>
#include <iostream>

#include "Events/Event.h"


Game::Game(Vector2i window_size):
    sdl::SdlUser({sdl::SdlSubsystem::Video, sdl::SdlSubsystem::Events}),
    m_window("Roguelike", window_size.x, window_size.y, sdl::SdlWindow::WindowFlags::OpenGl)
{
    initialize();
}
 
void Game::run()
{
    while(true)
    {
        for(auto event = m_window.poll_event(); event != nullptr; event = m_window.poll_event())
        {
            if(event->type() == Event::Type::Quit)
            {
                return;
            }
        }
        m_context->clear({gl::ClearTarget::ColorBuffer, gl::ClearTarget::DepthBuffer,
            gl::ClearTarget::StencilBuffer}); 
        m_window.swap_window();
    }
} 
void Game::initialize()
{
    initialize_open_gl(); 
}
 
void Game::initialize_open_gl()
{
    sdl::SdlGlContext::ContextSettings settings;
    settings.major_version = 3;
    settings.minor_version = 1;
    settings.vsync = 1;    
    settings.red_depth = 8;
    settings.green_depth = 8;
    settings.blue_depth = 8;
    settings.alpha_depth = 8;
    settings.depth_buffer_size = 24;
    settings.stencil_buffer_size = 8;
    settings.double_buffer = true;

    m_context = std::make_unique<sdl::SdlGlContext>(m_window, settings);
}
 

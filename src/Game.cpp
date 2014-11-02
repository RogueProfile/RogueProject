#include "Game.h"

#include <thread>
#include <chrono>
#include <iostream>

#include "sdl/Events/Event.h"

#include "GlHeaders.h"

#include "Screen.h"

Game::Game(Vector2i window_size):
    sdl::SdlUser({sdl::SdlSubsystem::Video, sdl::SdlSubsystem::Events}),
    m_window("Roguelike", window_size.x, window_size.y, sdl::SdlWindow::WindowFlags::OpenGl)
{
    initialize();
}
 
void Game::run()
{
    m_is_running = true;
    while(m_is_running)
    {
        m_frame_start_time = Clock::now();
        for(auto event = m_window.poll_event(); event != nullptr; event = m_window.poll_event())
        {
            if(event->type() == sdl::Event::Type::Quit)
            {
                return;
            }
        }
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
            std::this_thread::sleep_for(std::chrono::microseconds(static_cast<uint32_t>(sleep_time)));
        }
    }
} 
void Game::initialize()
{
    if(glewInit() != GLEW_OK)
    {
        //TODO: Exception
    }
    initialize_open_gl(); 
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
 

#ifndef SDLGLCONTEXT_H__
#define SDLGLCONTEXT_H__

#include "gl/GlContext.h"

#include "SdlWindow.h"

namespace sdl
{

class SdlGlContext : public gl::GlContext
{
public:
    static constexpr auto NullHandle = SDL_GLContext(0);

    struct ContextSettings
    {
        int major_version = 1;
        int minor_version = 1;
        
        int red_depth = 8;
        int green_depth = 8;
        int blue_depth = 8;
        int alpha_depth = 8;

        bool double_buffer = true;
        int depth_buffer_size = 24;
        int stencil_buffer_size = 0;

        bool vsync = false;
    };

    SdlGlContext(const SdlWindow& window, const ContextSettings& ctx);
    ~SdlGlContext();

    SdlGlContext(const SdlGlContext& other) = delete;
    SdlGlContext(SdlGlContext&& other) noexcept;
    SdlGlContext& operator =(const SdlGlContext& other) = delete;
    SdlGlContext& operator =(SdlGlContext&& other) noexcept;

protected:
    void destroy();
    void apply_context_settings(const ContextSettings& ctx);

    SDL_GLContext m_handle = NullHandle;
private:
};

}
#endif
    

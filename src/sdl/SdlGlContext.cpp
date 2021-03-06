#include "SdlGlContext.h"

#include "sdl/SdlException.h"

namespace sdl
{

SdlGlContext::SdlGlContext(const SdlWindow& window, const ContextSettings& ctx)
{
    apply_context_settings(ctx); 
    m_handle = SDL_GL_CreateContext(window.get_handle());     
    if(m_handle == NullHandle)
    {
        throw SdlException(SDL_GetError());
    }
    GlContext::initialize();
}
 
SdlGlContext::~SdlGlContext()
{
    destroy(); 
}
 
void SdlGlContext::destroy()
{
    if(m_handle != NullHandle)
    {
        SDL_GL_DeleteContext(m_handle);
    } 
}
 
void SdlGlContext::apply_context_settings(const ContextSettings& ctx)
{
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, ctx.red_depth);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, ctx.green_depth);    
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, ctx.blue_depth);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, ctx.alpha_depth);
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, ctx.major_version);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, ctx.minor_version);

    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, ctx.depth_buffer_size);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, ctx.stencil_buffer_size);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, (ctx.double_buffer == true ? 1 : 0));

    SDL_GL_SetSwapInterval(ctx.vsync == true ? 1 : 0);
}

}

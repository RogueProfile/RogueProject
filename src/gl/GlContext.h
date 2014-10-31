#ifndef GLCONTEXT_H__
#define GLCONTEXT_H__

#include "GlHeaders.h"

#include "Flags.h"

namespace gl
{
    class GlObject;

enum class ClearTarget
{
    ColorBuffer = GL_COLOR_BUFFER_BIT,
    DepthBuffer = GL_DEPTH_BUFFER_BIT,
    StencilBuffer = GL_STENCIL_BUFFER_BIT
};

class GlContext
{
public:
    GlContext() = default;
    ~GlContext() = default;

    GlContext(const GlContext& other) = delete;
    GlContext(GlContext&& other) noexcept = default;
    GlContext& operator =(const GlContext& other) = delete;
    GlContext& operator =(GlContext&& other) = default;

    void clear(const Flags<ClearTarget>& buffers);

private:

    GlObject* m_bound_shader_program = nullptr;

};

}

#endif
    

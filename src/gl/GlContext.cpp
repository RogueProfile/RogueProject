#include "GlContext.h"

#include <iostream>

namespace gl
{

void GlContext::clear(const Flags<ClearTarget>& buffers)
{
    glClear(buffers.get_raw_value()); 
}

BoundShaderProgram GlContext::bind_shader_program(ShaderProgram* program)
{
    glUseProgram(program->handle());
    return BoundShaderProgram(program, TargetLock(program, 
        &m_bound_shader_program));
}
 
}

#ifndef GL_ENUMS_H__
#define GL_ENUMS_H__

#include "GlHeaders.h"

enum class BufferBindTarget: GLenum
{
    VertexBuffer = GL_ARRAY_BUFFER,
    IndexBuffer = GL_ELEMENT_ARRAY_BUFFER
};

#endif

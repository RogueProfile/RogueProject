#ifndef GL_ENUMS_H__
#define GL_ENUMS_H__

#include "GlHeaders.h"

enum class BufferBindTarget: GLenum
{
    VertexBuffer = GL_ARRAY_BUFFER,
    IndexBuffer = GL_ELEMENT_ARRAY_BUFFER
};

enum class VertexComponentType
{
    Byte = GL_BYTE,
    UByte = GL_UNSIGNED_BYTE,
    Short = GL_SHORT,
    UShort = GL_UNSIGNED_SHORT,
    Int = GL_INT,
    UInt = GL_UNSIGNED_INT,
    Float = GL_FLOAT,
    Double = GL_DOUBLE
};

enum class IndexFormat
{
    Byte = GL_BYTE,
    UShort = GL_UNSIGNED_SHORT,
    UInt = GL_UNSIGNED_INT
};

#endif

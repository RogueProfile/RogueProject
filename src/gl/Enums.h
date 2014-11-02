#ifndef GL_ENUMS_H__
#define GL_ENUMS_H__

#include "GlHeaders.h"

namespace gl
{

enum class BufferBindTarget: GLenum
{
    VertexBuffer = GL_ARRAY_BUFFER,
    IndexBuffer = GL_ELEMENT_ARRAY_BUFFER,
    CopyWriteBuffer = GL_COPY_WRITE_BUFFER
};

enum class VertexComponentType: GLenum
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

enum class PrimitiveType: GLenum
{
    Points = GL_POINTS,
    Lines = GL_LINES,
    LineStrip = GL_LINE_STRIP,
    LineLoop = GL_LINE_LOOP,
    Triangles = GL_TRIANGLES,
    TriangleStrip = GL_TRIANGLE_STRIP,
    TriangleFan = GL_TRIANGLE_FAN,
};

enum class IndexFormat: GLenum
{
    Byte = GL_BYTE,
    UShort = GL_UNSIGNED_SHORT,
    UInt = GL_UNSIGNED_INT
};

}

#endif

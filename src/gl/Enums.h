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

enum class BufferUsageType: GLenum
{
	StaticDraw = GL_STATIC_DRAW,
	StaticRead = GL_STATIC_READ,
	StaticCopy = GL_STATIC_COPY,
	DynamicDraw = GL_DYNAMIC_DRAW,
	DynamicRead = GL_DYNAMIC_READ,
	DynamicCopy = GL_DYNAMIC_COPY,
	StreamDraw = GL_STREAM_DRAW,
	StreamRead = GL_STREAM_READ,
	StreamCopy = GL_STREAM_COPY
};

enum class IndexFormat: GLenum
{
    UByte = GL_UNSIGNED_BYTE,
    UShort = GL_UNSIGNED_SHORT,
    UInt = GL_UNSIGNED_INT
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

}

#endif

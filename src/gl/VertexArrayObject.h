#ifndef GL_VERTEXARRAYOBJECT_H__
#define GL_VERTEXARRAYOBJECT_H__

#include "GlObject.h"

namespace gl
{

class VertexArrayObject: public GlObject
{
public:
    VertexArrayObject();
    ~VertexArrayObject();

    VertexArrayObject(const VertexArrayObject& other) = delete;
    VertexArrayObject(VertexArrayObject&& other) noexcept;
    VertexArrayObject& operator =(const VertexArrayObject& other) = delete;
    VertexArrayObject& operator =(VertexArrayObject&& other) noexcept;

protected:
    virtual void destroy() override;
private:
};

}

#endif
    

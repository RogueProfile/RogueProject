#ifndef GL_VERTEXARRAYOBJECT_H__
#define GL_VERTEXARRAYOBJECT_H__

#include "GlObject.h"

#include <memory>
#include <unordered_map>

#include "VertexAttributeSource.h"

namespace gl
{
class IndexBufferObject;

class VertexArrayObject: public GlObject
{
    friend class BoundVertexArrayObject;
public:
    VertexArrayObject();
    ~VertexArrayObject();

    VertexArrayObject(const VertexArrayObject& other) = delete;
    VertexArrayObject(VertexArrayObject&& other) noexcept;
    VertexArrayObject& operator =(const VertexArrayObject& other) = delete;
    VertexArrayObject& operator =(VertexArrayObject&& other) noexcept;

protected:
    virtual void destroy() override;
    
    std::unordered_map<unsigned int, VertexAttributeSource> m_attrib_sources;
    std::shared_ptr<IndexBufferObject> m_index_buffer;
};

}

#endif
    

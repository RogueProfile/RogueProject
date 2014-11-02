#ifndef GL_BOUNDVERTEXARRAYOBJECT_H__
#define GL_BOUNDVERTEXARRAYOBJECT_H__

#include <cstdint>
#include <memory>

#include "TargetLock.h"

#include "Enums.h"

namespace gl
{
class VertexArrayObject;
class BoundVertexBufferObject;
class IndexBufferObject;

class BoundVertexArrayObject
{
public:
    BoundVertexArrayObject(VertexArrayObject* vertex_array,
            TargetLock lock);
    ~BoundVertexArrayObject();

    BoundVertexArrayObject(const BoundVertexArrayObject& other) = delete;
    BoundVertexArrayObject(BoundVertexArrayObject&& other) noexcept;
    BoundVertexArrayObject& operator =(const BoundVertexArrayObject& other) = delete;
    BoundVertexArrayObject& operator =(BoundVertexArrayObject&& other) noexcept;

    void attach_vertex_buffer(const BoundVertexBufferObject& vertex_buffer,
            unsigned int attribute_index, int components,
            VertexComponentType component_type, size_t stride, uintptr_t offset,
            bool normalize);

    void set_index_buffer(std::shared_ptr<IndexBufferObject> index_buffer);

    VertexArrayObject* vertex_array() {return m_vertex_array;}
    std::shared_ptr<IndexBufferObject> index_buffer() {return m_index_buffer;}
    std::shared_ptr<const IndexBufferObject> index_buffer() const {return m_index_buffer;}
    
    VertexArrayObject& array_object() {return *m_vertex_array;}     

protected:
    std::shared_ptr<IndexBufferObject> m_index_buffer;

    VertexArrayObject* m_vertex_array;
    TargetLock m_lock;
private:
};

}

#endif
    

#include "BoundVertexArrayObject.h"

#include <utility>

#include "VertexArrayObject.h"
#include "GlMacros.h"
#include "GlError.h"
#include "IndexBufferObject.h"

namespace gl
{

 
BoundVertexArrayObject::BoundVertexArrayObject(VertexArrayObject* vertex_array,
       TargetLock lock):
    m_vertex_array(vertex_array), m_lock(std::move(lock))
{
}
 
BoundVertexArrayObject::~BoundVertexArrayObject()
{
    glBindVertexArray(0); 
}
 
BoundVertexArrayObject::BoundVertexArrayObject(BoundVertexArrayObject&& other) noexcept:
    m_vertex_array(other.m_vertex_array), m_lock(std::move(other.m_lock))
{
    other.m_vertex_array = nullptr; 
}
 
BoundVertexArrayObject& BoundVertexArrayObject::operator=(BoundVertexArrayObject&& other) noexcept
{
    m_vertex_array = other.m_vertex_array;
    other.m_vertex_array = nullptr;
    m_lock = std::move(other.m_lock);
    return *this;
}
 
void BoundVertexArrayObject::attach_vertex_buffer(const BoundVertexBufferObject& vertex_buffer,
    unsigned int attribute_index, int components, VertexComponentType component_type,
    size_t stride, uintptr_t offset, bool normalize)
{
    glEnableVertexAttribArray(attribute_index);
    CHECK_GL_ERROR(glEnableVertexAttribArray);    
    glVertexAttribPointer(attribute_index, components, static_cast<GLenum>(component_type),
            normalize == true ? 1 : 0, stride, reinterpret_cast<void*>(offset));
    CHECK_GL_ERROR(glVertexAttribPointer);
}
 
void BoundVertexArrayObject::set_index_buffer(std::shared_ptr<IndexBufferObject> index_buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->handle()); 
    CHECK_GL_ERROR(glBindBuffer);
}
 
}


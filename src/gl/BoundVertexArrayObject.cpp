#include "BoundVertexArrayObject.h"

#include <utility>

#include "VertexArrayObject.h"
#include "GlMacros.h"
#include "GlError.h"
#include "IndexBufferObject.h"
#include "VertexAttributeSource.h"

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
 
void BoundVertexArrayObject::set_vertex_attrib_source(unsigned int attribute_index,
    int num_components, std::shared_ptr<BufferObject> buffer,
    VertexComponentType component_type, size_t stride, uintptr_t offset, bool normalize)
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer->handle());
    CHECK_GL_ERROR(glBindBuffer);
    glEnableVertexAttribArray(attribute_index);
    CHECK_GL_ERROR(glEnableVertexAttribArray);    
    glVertexAttribPointer(attribute_index, num_components, static_cast<GLenum>(component_type),
            normalize == true ? 1 : 0, stride, reinterpret_cast<void*>(offset));
    CHECK_GL_ERROR(glVertexAttribPointer);
    m_vertex_array->m_attrib_sources.emplace(std::make_pair(attribute_index,
        VertexAttributeSource(std::move(buffer),
            num_components, stride, offset, component_type, normalize)));
}
 
void BoundVertexArrayObject::set_vertex_attrib_sources(std::shared_ptr<BufferObject> buffer,
    const std::pair<unsigned int, AttributeParams>* attrib_params, size_t count)
{
    glBindBuffer(GL_ARRAY_BUFFER, buffer->handle());
    CHECK_GL_ERROR(glBindBuffer);
    for(auto i = 0; i < count; ++i)
    {
        auto attrib_index = attrib_params[i].first;
        glEnableVertexAttribArray(attrib_index);
        CHECK_GL_ERROR(glEnableVertexAttribArray);    
        auto& params = attrib_params[i].second;
        glVertexAttribPointer(attrib_index, params.num_components,
            static_cast<GLenum>(params.component_type),
            params.normalize == true ? 1 : 0, params.stride,
            reinterpret_cast<void*>(params.offset));
        CHECK_GL_ERROR(glVertexAttribPointer);
        m_vertex_array->m_attrib_sources.emplace(std::make_pair(attrib_index,
            VertexAttributeSource(buffer, params.num_components, params.stride,
                params.offset, params.component_type, params.normalize)));
    }
}
 
void BoundVertexArrayObject::set_index_buffer(std::shared_ptr<IndexBufferObject> index_buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer->handle()); 
    CHECK_GL_ERROR(glBindBuffer);
    m_vertex_array->m_index_buffer = std::move(index_buffer);
}
 
}

 

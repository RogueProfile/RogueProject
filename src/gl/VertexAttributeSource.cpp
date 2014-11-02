#include "VertexAttributeSource.h"

#include "BufferObject.h"

namespace gl
{

VertexAttributeSource::VertexAttributeSource(std::shared_ptr<BufferObject> buffer,
        int num_components, size_t stride, uintptr_t offset,
        VertexComponentType component_type, bool normalize):
    m_buffer(std::move(buffer)), m_num_components(num_components),
    m_stride(stride), m_offset(offset), m_component_type(component_type),
    m_normalize(normalize)
{
}
 
VertexAttributeSource::VertexAttributeSource(const VertexAttributeSource& other):
    m_buffer(other.m_buffer), m_num_components(other.m_num_components),
    m_stride(other.m_stride), m_offset(other.m_offset), m_component_type(other.m_component_type),
    m_normalize(other.m_normalize)
{
 
}
 
VertexAttributeSource::VertexAttributeSource(VertexAttributeSource&& other) noexcept:
    m_buffer(std::move(other.m_buffer)), m_num_components(other.m_num_components), 
    m_stride(other.m_stride), m_offset(other.m_offset), m_component_type(other.m_component_type),
    m_normalize(other.m_normalize)
{
 
}
 
VertexAttributeSource& VertexAttributeSource::operator=(const VertexAttributeSource& other)
{
    m_buffer = other.m_buffer; 
    m_num_components = other.m_num_components;
    m_stride = other.m_stride;
    m_offset = other.m_offset;
    m_component_type = other.m_component_type;
    m_normalize = other.m_normalize;
    return *this;
}
 
VertexAttributeSource& VertexAttributeSource::operator=(VertexAttributeSource&& other) noexcept
{
    m_buffer = std::move(other.m_buffer); 
    m_num_components = other.m_num_components;
    m_stride = other.m_stride;
    m_offset = other.m_offset;
    m_component_type = other.m_component_type;
    m_normalize = other.m_normalize;
    return *this;
}
 
}


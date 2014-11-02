#ifndef GL_VERTEXATTRIBUTESOURCE_H__
#define GL_VERTEXATTRIBUTESOURCE_H__

#include <memory>
#include <cstdint>

#include "Enums.h"

namespace gl
{
class BufferObject;

class VertexAttributeSource
{
public:
    VertexAttributeSource(std::shared_ptr<BufferObject> buffer,
            int num_components, size_t stride, uintptr_t offset,
            VertexComponentType component_type, bool normalize);
    ~VertexAttributeSource() = default;

    VertexAttributeSource(const VertexAttributeSource& other);
    VertexAttributeSource(VertexAttributeSource&& other) noexcept;
    VertexAttributeSource& operator =(const VertexAttributeSource& other);
    VertexAttributeSource& operator =(VertexAttributeSource&& other) noexcept;

    std::shared_ptr<BufferObject> buffer() {return m_buffer;}
    size_t stride() const {return m_stride;}
    uintptr_t offset() const {return m_offset;}
    VertexComponentType component_type() const {return m_component_type;}
    bool normalize() const {return m_normalize;}

protected:
    std::shared_ptr<BufferObject> m_buffer;
    int m_num_components;
    size_t m_stride;
    uintptr_t m_offset;
    VertexComponentType m_component_type;
    bool m_normalize;
};

}

#endif
    

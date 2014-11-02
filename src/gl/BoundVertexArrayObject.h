#ifndef GL_BOUNDVERTEXARRAYOBJECT_H__
#define GL_BOUNDVERTEXARRAYOBJECT_H__

#include <cstdint>
#include <memory>
#include <array>

#include "TargetLock.h"

#include "Enums.h"

namespace gl
{
class VertexArrayObject;
class IndexBufferObject;
class BufferObject;
class VertexAttributeSource;

class BoundVertexArrayObject
{
public:
    struct AttributeParams
    {
        unsigned int num_components = 1;
        size_t stride = 0;
        uintptr_t offset = 0;
        VertexComponentType component_type = VertexComponentType::Float;
        bool normalize = false;
    };
    BoundVertexArrayObject(VertexArrayObject* vertex_array,
            TargetLock lock);
    ~BoundVertexArrayObject();

    BoundVertexArrayObject(const BoundVertexArrayObject& other) = delete;
    BoundVertexArrayObject(BoundVertexArrayObject&& other) noexcept;
    BoundVertexArrayObject& operator =(const BoundVertexArrayObject& other) = delete;
    BoundVertexArrayObject& operator =(BoundVertexArrayObject&& other) noexcept;

    void set_vertex_attrib_source(unsigned int attribute_index,
        int num_components, std::shared_ptr<BufferObject> buffer,
        VertexComponentType component_type, size_t stride=0, uintptr_t offset=0,
        bool normalize=false);

    void set_vertex_attrib_sources(std::shared_ptr<BufferObject> buffer,
        const std::pair<unsigned int, AttributeParams>* attrib_params,
        size_t count); 

    template<size_t N>
    void set_vertex_attrib_sources(std::shared_ptr<BufferObject> buffer,
        const std::array<std::pair<unsigned int, AttributeParams>, N>& attrib_params)
            {set_vertex_attrib_sources(std::move(buffer), attrib_params.data, N);}

    void set_index_buffer(std::shared_ptr<IndexBufferObject> index_buffer);

    VertexArrayObject& array_object() {return *m_vertex_array;}     

protected:
    VertexArrayObject* m_vertex_array;
    TargetLock m_lock;
};

}

#endif
    

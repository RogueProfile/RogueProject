#ifndef TILEGRIDRENDERER_H__
#define TILEGRIDRENDERER_H__

#include <memory>
#include <cstdint>

#include "Matrix3.h"

namespace gl
{
    class ShaderProgram;
    class BufferObject;
    class IndexBufferObject;
    class GlContext;
    class VertexArrayObject;
}

class TileSet;
class TileGrid;

class TileGridRenderer
{
public:
    TileGridRenderer(gl::GlContext* context,
        std::shared_ptr<gl::ShaderProgram> shader,
        const Matrix3f& transform,
        TileSet* tile_set, const TileGrid* tile_grid);
    ~TileGridRenderer();

    TileGridRenderer(const TileGridRenderer& other) = delete;
    TileGridRenderer(TileGridRenderer&& other) noexcept = delete;
    TileGridRenderer& operator =(const TileGridRenderer& other) = delete;
    TileGridRenderer& operator =(TileGridRenderer&& other) noexcept = delete;

    void set_transform(const Matrix3f& transform);

    void render();

    static std::shared_ptr<gl::ShaderProgram> create_default_shader(gl::GlContext* context);
protected:
    struct DynVertexAttribs
    {
        float u;
        float v;
        float layer;
        uint32_t fg_color;
        uint32_t bg_color;
    };

    void fill_static_vertex_attribs();
    void fill_dynamic_vertex_attribs();
    void build_vertex_array_object();
    void create_dynamic_vertex_buffer();
    void create_static_buffers();

    static constexpr int vertices_per_tile() {return 4;}
    static constexpr int indices_per_tile() {return 6;}

    std::shared_ptr<gl::BufferObject> m_static_vertex_attribs;
    std::shared_ptr<gl::BufferObject> m_dynamic_vertex_attribs;
    std::shared_ptr<gl::IndexBufferObject> m_index_buffer;
    std::unique_ptr<gl::VertexArrayObject> m_vao;

    Matrix3f m_transform;

    TileSet* m_tile_set;
    const TileGrid* m_grid;
    gl::GlContext* m_context;

    std::shared_ptr<gl::ShaderProgram> m_shader;

private:
};


#endif
    

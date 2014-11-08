#include "TileGridRenderer.h"

#include <utility>
#include <cstddef>
#include <iostream>

#include "gl/ShaderProgram.h"
#include "gl/BufferObject.h"
#include "gl/IndexBufferObject.h"
#include "gl/GlContext.h"
#include "gl/BoundBufferObject.h"
#include "gl/VertexArrayObject.h"
#include "gl/BoundVertexArrayObject.h"
#include "gl/BoundShaderProgram.h"
#include "gl/BoundTextureArray2d.h"
#include "gl/VertexBufferObject.h"

#include "TileGrid.h"
#include "TileSet.h"

TileGridRenderer::TileGridRenderer(gl::GlContext* context,
        std::shared_ptr<gl::ShaderProgram> shader,
        const Matrix3f& transform,
        TileSet* tile_set, const TileGrid* tile_grid):
    m_context(context), m_shader(std::move(shader)), m_transform(transform),
    m_tile_set(tile_set), m_grid(tile_grid)
{
    m_dynamic_vertex_attribs = std::make_shared<gl::VertexBufferObject>(
            m_context, gl::BufferUsageType::StreamDraw,
            m_grid->width() * m_grid->height() * sizeof(DynVertexAttribs) * 4);
    fill_static_vertex_attribs();
    build_vertex_array_object();
}

TileGridRenderer::~TileGridRenderer()
{
 
}

void TileGridRenderer::fill_static_vertex_attribs()
{
    m_static_vertex_attribs = std::make_shared<gl::VertexBufferObject>(
        m_context, gl::BufferUsageType::StaticDraw,
        m_grid->width() * m_grid->height() * sizeof(float) * 2 * 4);

    m_index_buffer = std::make_shared<gl::IndexBufferObject>(
        m_context, gl::BufferUsageType::StaticDraw,
        m_grid->width() * m_grid->height() * sizeof(unsigned int) * 6,
        gl::IndexFormat::UInt);

    auto bound_vbo = m_context->bind_buffer_object(*m_static_vertex_attribs);
    auto mapped_buffer = bound_vbo.map<float>(false);
    bound_vbo.release();

    auto bound_ibo = m_context->bind_buffer_object(*m_index_buffer);
    auto mapped_index_buffer = bound_ibo.map<unsigned int>(false);

    auto tile_width = m_tile_set->tile_width();
    auto tile_height = m_tile_set->tile_height();

    auto component_index = 0;
    auto index_index = 0;
    unsigned int index_base = 0;

    for(auto x = 0; x < m_grid->width(); ++x)
    {
        for(auto y = 0; y < m_grid->height(); ++y)
        {
            mapped_buffer[component_index++] = x * tile_width;     
            mapped_buffer[component_index++] = y * tile_height;     
            mapped_buffer[component_index++] = x * tile_width;     
            mapped_buffer[component_index++] = (y+1) * tile_height;     
            mapped_buffer[component_index++] = (x+1) * tile_width;     
            mapped_buffer[component_index++] = (y+1) * tile_height;     
            mapped_buffer[component_index++] = (x+1) * tile_width;     
            mapped_buffer[component_index++] = y * tile_height;     

            mapped_index_buffer[index_index++] = index_base;
            mapped_index_buffer[index_index++] = index_base + 1;
            mapped_index_buffer[index_index++] = index_base + 2;
            mapped_index_buffer[index_index++] = index_base + 2;
            mapped_index_buffer[index_index++] = index_base + 3;
            mapped_index_buffer[index_index++] = index_base;
            index_base += 4;
        }
    }     
}

void TileGridRenderer::fill_dynamic_vertex_attribs()
{
    auto bound_vbo = m_context->bind_buffer_object(*m_dynamic_vertex_attribs);
    auto mapped_buffer = bound_vbo.map<DynVertexAttribs>(false);

    auto tile_width = m_tile_set->tile_width();
    auto tile_height = m_tile_set->tile_height();

    auto component_index = 0;

    for(auto x = 0; x < m_grid->width(); ++x)
    {
        for(auto y = 0; y < m_grid->height(); ++y)
        {
            const auto& tile = m_grid->get_tile(x, y);
            auto fg_color = tile.foreground_color().to_abgr();
            auto bg_color = tile.background_color().to_abgr();
            auto tile_loc = m_tile_set->get_tile_location(tile.tile_index());

            mapped_buffer[component_index].u = tile_loc.bottom_left.x;
            mapped_buffer[component_index].v = tile_loc.bottom_left.y;
            mapped_buffer[component_index].layer = tile_loc.layer;
            mapped_buffer[component_index].fg_color = fg_color;
            mapped_buffer[component_index].bg_color = bg_color;
            component_index += 1;

            mapped_buffer[component_index].u = tile_loc.bottom_left.x;
            mapped_buffer[component_index].v = tile_loc.top_right.y;
            mapped_buffer[component_index].layer = tile_loc.layer;
            mapped_buffer[component_index].fg_color = fg_color;
            mapped_buffer[component_index].bg_color = bg_color;
            component_index += 1;

            mapped_buffer[component_index].u = tile_loc.top_right.x;
            mapped_buffer[component_index].v = tile_loc.top_right.y;
            mapped_buffer[component_index].layer = tile_loc.layer;
            mapped_buffer[component_index].fg_color = fg_color;
            mapped_buffer[component_index].bg_color = bg_color;
            component_index += 1;

            mapped_buffer[component_index].u = tile_loc.top_right.x;
            mapped_buffer[component_index].v = tile_loc.bottom_left.y;
            mapped_buffer[component_index].layer = tile_loc.layer;
            mapped_buffer[component_index].fg_color = fg_color;
            mapped_buffer[component_index].bg_color = bg_color;
            component_index += 1;
        }
    }     
}
 
 
void TileGridRenderer::set_transform(const Matrix3f& transform)
{
    m_transform = transform; 
}
 
void TileGridRenderer::render()
{
    fill_dynamic_vertex_attribs(); 
    auto bound_shader = m_context->bind_shader_program(*m_shader);
    bound_shader.set_uniform_value(0, m_transform);
    auto bound_vao = m_context->bind_vertex_array(*m_vao);
    glActiveTexture(GL_TEXTURE0);
    auto bound_texture = m_context->bind_texture_array_2d(
        *reinterpret_cast<gl::TextureArray2d*>(m_tile_set->get_texture()));
    m_context->draw_vertex_array_indexed(bound_vao, gl::PrimitiveType::Triangles,
            0, 10*10*6);
}
 
std::shared_ptr<gl::ShaderProgram> TileGridRenderer::create_default_shader(gl::GlContext* context)
{
    std::string vertex_shader_source =
    R"(
    #version 140
    uniform mat3 transform;

    in vec2 position;
    in vec3 tex;
    in vec4 fg_color;
    in vec4 bg_color;

    out vec3 tex_coord;
    out vec4 foreground_color;
    out vec4 background_color;

    void main()
    {
        tex_coord = tex;
        foreground_color = fg_color;
        background_color = bg_color;
        gl_Position = vec4((transform * vec3(position, 1)).xy, 1, 1);
    }
    )";

    std::string fragment_shader_source =
    R"(
    #version 140

    uniform sampler2DArray tex_sampler;

    in vec3 tex_coord;
    in vec4 foreground_color;
    in vec4 background_color;

    out vec4 color_out;

    void main()
    {
        vec4 tex_color = texture(tex_sampler, tex_coord);
        vec4 fg_color = tex_color * foreground_color;
        color_out = vec4(fg_color.rgb * fg_color.a + background_color.rgb 
            * background_color.a * (1.0 - fg_color.a), fg_color.a + 
            background_color.a * (1.0 - fg_color.a));
    }
    )"; 

    auto vertex_shader = std::make_shared<gl::Shader>(gl::ShaderType::Vertex);
    vertex_shader->compile_source(vertex_shader_source);
    std::cout << "VERTEX: " << vertex_shader->get_info_log() << std::endl;
    auto fragment_shader = std::make_shared<gl::Shader>(gl::ShaderType::Fragment);
    fragment_shader->compile_source(fragment_shader_source);
    std::cout << "FRAGMENT: " << fragment_shader->get_info_log() << std::endl;

    auto shader_program = std::make_shared<gl::ShaderProgram>();
    shader_program->attach_shader(std::move(vertex_shader));
    shader_program->attach_shader(std::move(fragment_shader));
    shader_program->bind_attribute_location("position", 0);
    shader_program->bind_attribute_location("tex", 1);
    shader_program->bind_attribute_location("fg_color", 2);
    shader_program->bind_attribute_location("bg_color", 3);
    shader_program->link();
    std::cout << "PROGRAM: " << shader_program->get_info_log() << std::endl;
    return shader_program;
}
 
void TileGridRenderer::build_vertex_array_object()
{
    m_vao = std::make_unique<gl::VertexArrayObject>(m_context); 
    auto bound_vao = m_context->bind_vertex_array(*m_vao);

    bound_vao.set_vertex_attrib_source(0, 2, m_static_vertex_attribs,
            gl::VertexComponentType::Float);
    bound_vao.set_vertex_attrib_source(1, 3, m_dynamic_vertex_attribs,
            gl::VertexComponentType::Float, sizeof(DynVertexAttribs),
            offsetof(DynVertexAttribs, u));
    bound_vao.set_vertex_attrib_source(2, 4, m_dynamic_vertex_attribs,
            gl::VertexComponentType::UByte, sizeof(DynVertexAttribs),
            offsetof(DynVertexAttribs, fg_color), true);
    bound_vao.set_vertex_attrib_source(3, 4, m_dynamic_vertex_attribs,
            gl::VertexComponentType::UByte, sizeof(DynVertexAttribs),
            offsetof(DynVertexAttribs, bg_color), true);
    bound_vao.set_index_buffer(m_index_buffer);
}
 

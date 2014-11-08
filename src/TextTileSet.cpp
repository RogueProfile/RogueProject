#include "TextTileSet.h"

#include <utility>
#include <functional>

#include "gl/TextureArray2d.h"
#include "gl/GlContext.h"
#include "gl/BoundTextureArray2d.h"

#include "freetype/FontFace.h"
#include "freetype/BitmapGlyph.h"

TextTileSet::TextTileSet(gl::GlContext* context,
        std::shared_ptr<const ft::FontFace> font_face, int min_tile_slots):
    m_context(context), m_font_face(std::move(font_face)),
    m_tiles(min_tile_slots, std::bind(&TextTileSet::on_tile_drop, this,
            std::placeholders::_1, std::placeholders::_2))
{
    compute_geometries(min_tile_slots);
    m_texture = std::make_unique<gl::TextureArray2d>(
            m_context, texture_width(), texture_height(),
            m_texture_layers, 1, gl::Texture::InternalPixelFormat::RGBA8);            
    add_initial_slots();
}
 
TextTileSet::~TextTileSet()
{
}
 
int TextTileSet::tile_width() const
{
    return m_font_face->max_advance_width();
}

void TextTileSet::compute_geometries(int min_slots)
{
    auto g_character = std::static_pointer_cast<const ft::BitmapGlyph>(m_font_face->get_glyph('g'));
	int below_baseline = g_character->top() - g_character->rows();
	if(below_baseline > 0)
	{
		below_baseline = 0;
	}

    m_vert_shift = -below_baseline;
	m_tile_height = m_vert_shift + m_font_face->line_height();
    
    m_texture_layers = std::ceil(static_cast<float>(min_slots) /
           (tiles_per_line() * tile_lines()));

    m_cell_width = tile_width() / static_cast<double>(texture_width());
    m_cell_height = tile_height() / static_cast<double>(texture_height());

    auto tile_count = tiles_per_line() * tile_lines() * m_texture_layers;
    m_free_slots.resize(tile_count);
    m_tiles.resize(tile_count);
}
 
const TileSet::TileLocation& TextTileSet::get_tile_location(unsigned int id)
{
    const auto* cell = m_tiles.get_item(id);
    if(cell != nullptr)
    {
        return *cell;
    }
    else
    {
        auto& new_cell = m_free_slots.back();
        m_free_slots.pop_back();
        const auto& new_cell_ret = m_tiles.add_item(id, new_cell);
        add_glyph(new_cell, id);
        return new_cell_ret;
    }
}
 
gl::Texture* TextTileSet::get_texture()
{
    return m_texture.get(); 
}
 
void TextTileSet::add_initial_slots()
{
    auto slot_width = m_cell_width;
    auto slot_height = m_cell_height;

    auto last = m_free_slots.size()-1;

    auto index = 0;
    for(auto y = 0; y < tile_lines(); ++y)
    {
        float y_pos = y * slot_height;
        for(auto x = 0; x < tiles_per_line(); ++x)
        {
            float x_pos = x * slot_width;
            for(auto z = 0; z < m_texture_layers; ++z)
            {
                m_free_slots[last-index] = TileLocation{Vector2f(x_pos, y_pos),
                       Vector2f(x_pos+slot_width, y_pos+slot_height), z, 0};
                index += 1;
            }
        }
    }
}
 
void TextTileSet::add_glyph(const TileLocation& location, unsigned int character)
{
    auto glyph = std::static_pointer_cast<const ft::BitmapGlyph>(
        m_font_face->get_glyph(character)); 

    auto bitmap_data = copy_glyph_bitmap(*glyph); 

    Rectanglei tile_location(location.bottom_left.x * texture_width(),
            location.bottom_left.y * texture_height(),
            tile_width(), tile_height());
    
    auto bound_texture = m_context->bind_texture_array_2d(*m_texture);
    bound_texture.update_data(tile_location, location.layer, 1,
            gl::Texture::DataPixelFormat::BGRA, 
            gl::Texture::PixelType::UByte, bitmap_data.data());
}
 
std::vector<uint32_t> TextTileSet::copy_glyph_bitmap(const ft::BitmapGlyph& glyph) const
{
    auto bitmap_size = tile_width() * tile_height();  
    std::vector<uint32_t> bitmap_data(bitmap_size);
    
    const auto source_data = glyph.buffer();
    if(source_data)
    {
        for(auto y = 0; y < glyph.rows(); ++y)
        {
            for(auto x = 0; x < glyph.width(); ++x)
            {
                auto x_pos = x + glyph.left();
                auto y_pos = y + tile_height() - glyph.top() - m_vert_shift;
                auto index = x_pos + y_pos * tile_width();

                if(index < bitmap_size && index >= 0)
                {
                    bitmap_data[index] = 0x00FFFFFF | (source_data[x + y * glyph.pitch()] << 24);
                }
            }
        }
    }
    return bitmap_data;
}
 
void TextTileSet::on_tile_drop(const unsigned int& tile_id, const TileSet::TileLocation& location)
{
    m_free_slots.push_back(location); 
}
 

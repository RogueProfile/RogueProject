#ifndef TEXTTILESET_H__
#define TEXTTILESET_H__

#include "TileSet.h"

#include <memory>
#include <vector>

#include "LruCache.h"

namespace gl
{
    class Texture;
    class TextureArray2d;
    class GlContext;
}
namespace ft
{
    class FontFace;
    class BitmapGlyph;
}

class TextTileSet: public TileSet
{
public:
    TextTileSet(gl::GlContext* context,
            std::shared_ptr<const ft::FontFace> font_face, int min_tile_slots);
    virtual ~TextTileSet();

    TextTileSet(const TextTileSet& other) = delete;
    TextTileSet(TextTileSet&& other) noexcept = delete;
    TextTileSet& operator =(const TextTileSet& other) = delete;
    TextTileSet& operator =(TextTileSet&& other) noexcept = delete;

    virtual int tile_width() const override;
    virtual int tile_height() const override {return m_tile_height;}

    virtual const TileLocation& get_tile_location(TileIdType id) override;

    virtual gl::Texture* get_texture() override;

protected:
    void add_initial_slots();
    void compute_geometries(int min_slots);

    int tiles_per_line() const {return m_texture_width / tile_width();}
    int tile_lines() const {return m_texture_height / m_tile_height;}

    void add_glyph(const TileLocation& location, TileIdType character);
    std::vector<uint32_t> copy_glyph_bitmap(const ft::BitmapGlyph& glyph) const;

    std::unique_ptr<gl::TextureArray2d> m_texture;
    mutable LruCache<TileIdType, TileLocation> m_tiles;

    gl::GlContext* m_context;

    float m_cell_width;
    float m_cell_height;

    mutable std::vector<TileLocation> m_free_slots;
    std::shared_ptr<const ft::FontFace> m_font_face;
    static constexpr int m_texture_width = 1024;
    static constexpr int m_texture_height = 1024;
    int m_texture_layers;

    int m_tile_height;
    int m_vert_shift;
private:

    void on_tile_drop(const TileIdType& tile_id, const TileLocation& location);
};


#endif
    

#ifndef FT_FONTFACE_H__
#define FT_FONTFACE_H__

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include <memory>
#include <vector>

#include "Enums.h"
#include "Flags.h"

#include "LruCache.h"

namespace ft
{
class FreeTypeLibrary;
class Glyph;

struct BitmapFontSize
{
	short width;
	short height;

	float size;

	float x_pixels_per_em;
	float y_pixels_per_em;
};

struct CharMap
{
    CharMapEncoding encoding;
    unsigned short platform_id;
    unsigned short encoding_id;
};

class FontFace
{
public:
    FontFace(const FreeTypeLibrary& library,
        const std::shared_ptr<std::vector<unsigned char>>& font_data,
        int width, int height, int face_index,
        const Flags<GlyphLoadFlags>& glyph_flags);
    ~FontFace();

    FontFace(const FontFace& other) = default;
    FontFace(FontFace&& other) noexcept = default;
    FontFace& operator =(const FontFace& other) = default;
    FontFace& operator =(FontFace&& other) noexcept = default;

    std::string family_name() const;
    std::string style_name() const;

    int character_width() const {return m_face->size->metrics.x_ppem;}
	int face_index() const {return m_face->face_index;}
	int num_faces() const {return m_face->num_faces;}
    std::vector<BitmapFontSize> available_sizes() const;

    bool has_character(char32_t chr) const;

    unsigned short units_per_em() const {return m_face->units_per_EM;}

	int line_height() const {return m_face->size->metrics.height >> 6;}
	int max_advance_width() const {return m_face->size->metrics.max_advance >> 6;}

	int fixed_size_count() const {return m_face->num_fixed_sizes;}

    float underline_position() const 
        {return frac_266_to_float(FT_MulFix(m_face->underline_position, m_face->size->metrics.y_scale));}
    float underline_thickness() const 
        {return frac_266_to_float(FT_MulFix(m_face->underline_thickness, m_face->size->metrics.y_scale));}

	float ascender() const {return m_face->size->metrics.ascender / 64.f;}
	float descender() const {return m_face->size->metrics.descender / 64.f;}

    int char_map_count() const {return m_face->num_charmaps;}
    std::vector<CharMap> char_maps() const;
	CharMap current_char_map() const;
	bool has_char_map(CharMapEncoding encoding) const;

    std::shared_ptr<Glyph> get_glyph(char32_t character) const;

    long glyph_count() const {return m_face->num_glyphs;}
	Flags<FaceStyleFlags> get_style_flags() const 
        {return Flags<FaceStyleFlags>(static_cast<FaceStyleFlags>(m_face->style_flags));}
	Flags<FaceFlags> get_flags() const {return Flags<FaceFlags>(static_cast<FaceFlags>(m_face->face_flags));}
	Flags<GlyphLoadFlags> get_glyph_flags() const {return m_glyph_flags;}

    int get_kerning_offset(char32_t left_char, char32_t right_char,
        KerningMode mode = KerningMode::Default) const;

    void set_character_size_in_points(float size_in_points, float dpi_x = 72., float dpi_y = 72.);
    void set_character_size(int width, int height);

    void select_fixed_size(int index);

    void select_char_map(CharMapEncoding encoding);

    void set_glyph_load_flag(GlyphLoadFlags flag) {invalidate_cache(); m_glyph_flags.set_flag(flag);}
    void unset_glyph_load_flag(GlyphLoadFlags flag) {invalidate_cache(); m_glyph_flags.clear_flag(flag);}
    void set_glyph_load_flags(const Flags<GlyphLoadFlags>& flags) {invalidate_cache(); m_glyph_flags = flags;}

protected:
    constexpr static float frac_266_to_float(int val) {return val / 64.f;}

    std::shared_ptr<Glyph> construct_glyph_object(FT_Glyph glyph) const;
    FT_Glyph load_glyph(char32_t chr) const;

    void invalidate_cache() const;

    mutable LruCache<char32_t, std::shared_ptr<Glyph>> m_cache;

    std::shared_ptr<std::vector<unsigned char>> m_font_data;

    FT_Face m_face = nullptr;
    Flags<GlyphLoadFlags> m_glyph_flags;
private:
};

}

#endif
    

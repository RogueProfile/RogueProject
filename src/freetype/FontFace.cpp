#include "FontFace.h"

#include "FreeTypeError.h"
#include "FreeTypeLibrary.h"

#include "Glyph.h"
#include "BitmapGlyph.h"

namespace ft
{

FontFace::FontFace(const FreeTypeLibrary& library,
        const std::shared_ptr<std::vector<unsigned char>>& font_data,
        int width, int height, int face_index,
        const Flags<GlyphLoadFlags>& glyph_flags):
    m_font_data(font_data), m_glyph_flags(glyph_flags), m_cache(500)
    
{
    auto error = FT_New_Memory_Face(library.ft_object(), font_data.get()->data(),
        font_data.get()->size(), face_index, &m_face);
    if(error)
    {
        throw FreeTypeError("Unable to create new font face", error);
    }
    set_character_size(width, height);
}
 
FontFace::~FontFace()
{
    if(m_face != nullptr)
    {
        FT_Done_Face(m_face);
    } 
}
 
std::string FontFace::family_name() const
{
    if(m_face->family_name)
    {
        return std::string(m_face->family_name);
    }
    return std::string(""); 
}
 
std::string FontFace::style_name() const
{
    if(m_face->style_name)
    {
        return std::string(m_face->style_name);
    }
    return std::string("");
}
 
std::vector<BitmapFontSize> FontFace::available_sizes() const
{
    std::vector<BitmapFontSize> sizes(fixed_size_count());
	for(auto i = 0; i < fixed_size_count(); ++i)
	{
		auto& size_data = m_face->available_sizes[i];
		sizes[i].height = size_data.height;
		sizes[i].width = size_data.width;
		sizes[i].size = frac_266_to_float(size_data.size);
		sizes[i].x_pixels_per_em = frac_266_to_float(size_data.x_ppem);
		sizes[i].y_pixels_per_em = frac_266_to_float(size_data.y_ppem);
	}
	return sizes;  
}
 
bool FontFace::has_character(char32_t chr) const
{
    return FT_Get_Char_Index(m_face, chr) != 0; 
}
 
std::vector<CharMap> FontFace::char_maps() const
{
    std::vector<CharMap> maps(char_map_count());

	for(auto i = 0; i < char_map_count(); ++i)
	{
		auto char_data = m_face->charmaps[i];
		maps[i].encoding = static_cast<CharMapEncoding>(char_data->encoding);
		maps[i].encoding_id = char_data->encoding_id;
		maps[i].platform_id = char_data->platform_id;
	}
	return maps; 
}
 
CharMap FontFace::current_char_map() const
{
    CharMap map;
	map.encoding = static_cast<CharMapEncoding>(m_face->charmap->encoding);
	map.encoding_id = m_face->charmap->encoding_id;
	map.platform_id = m_face->charmap->platform_id;
	return map;
}
 
bool FontFace::has_char_map(CharMapEncoding encoding) const
{
    for(auto i = 0; i < char_map_count(); ++i)
	{
		if(static_cast<CharMapEncoding>(m_face->charmaps[i]->encoding) == encoding)
		{
			return true;
		}
	}
	return false; 
}
 
void FontFace::set_character_size_in_points(float size_in_points, float dpi_x, float dpi_y)
{
    invalidate_cache();
    int error = FT_Set_Char_Size(m_face, 0, static_cast<int>(size_in_points / 64.), dpi_x, dpi_y);
    if(error != 0)
    {
        throw FreeTypeError("Unable to set font size", error);
    }
}
 
void FontFace::set_character_size(int width, int height)
{
    invalidate_cache();
    int error = FT_Set_Pixel_Sizes(m_face, width, height);
    if(error)
    {
        throw FreeTypeError("Unable to set font size", error);
    } 
}
 
std::shared_ptr<Glyph> FontFace::get_glyph(char32_t character) const
{
    auto glyph_ptr = m_cache.get_item(character);
	if(glyph_ptr == nullptr)
	{
		FT_Glyph ft_glyph = load_glyph(character);

		auto glyph = construct_glyph_object(ft_glyph);
		m_cache.add_item(character, glyph);
		return glyph;
	}
	else
	{
		return *glyph_ptr;
	}
}

int FontFace::get_kerning_offset(char32_t left_char, char32_t right_char,
        KerningMode mode) const
{
    FT_Vector kerning;
    int error = FT_Get_Kerning(m_face, left_char, right_char,
        static_cast<FT_Kerning_Mode>(mode), &kerning);
    if(error != 0)
    {
        throw FreeTypeError("Failed to get kerning offset", error);
    }
    return kerning.x >> 8;
}
 
void FontFace::select_fixed_size(int index)
{
    invalidate_cache();
	int error = FT_Select_Size(m_face, index);
	if(error)
	{
		throw FreeTypeError("Unable to set font size", error);
	} 
}
 
void FontFace::select_char_map(CharMapEncoding encoding)
{
    invalidate_cache();
	int error = FT_Select_Charmap(m_face, static_cast<FT_Encoding>(encoding));
	if(error)
	{
		throw FreeTypeError("Unable to set char map", error);
	}    
}
 
void FontFace::invalidate_cache() const
{
    m_cache.clear(); 
}

std::shared_ptr<Glyph> FontFace::construct_glyph_object(FT_Glyph glyph) const
{
	if(glyph->format == FT_GLYPH_FORMAT_BITMAP)
	{
		return std::make_shared<BitmapGlyph>(reinterpret_cast<FT_BitmapGlyph>(glyph));
	}
	else
	{
		return std::make_shared<Glyph>(glyph);
	}
}

FT_Glyph FontFace::load_glyph(char32_t chr) const
{
	FT_Glyph glyph;

	auto glyph_index = FT_Get_Char_Index(m_face, chr);
	auto error = FT_Load_Glyph(m_face, glyph_index, m_glyph_flags.get_raw_value());
	if(error)
	{
		throw FreeTypeError("Unable to load glyph", error);
	}
	error = FT_Get_Glyph(m_face->glyph, &glyph);
	if(error)
	{
		throw FreeTypeError("FT_Get_Glyph failed", error);
	}

	return glyph;
}
 
}


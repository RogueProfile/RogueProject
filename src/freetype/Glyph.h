#ifndef FT_GLYPH_H__
#define FT_GLYPH_H__

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

#include <memory>

#include "Rectangle.h"

#include "Enums.h"

namespace ft
{
class BitmapGlyph;

class Glyph
{
    friend class BitmapGlyph;
public:
    explicit Glyph(FT_Glyph glyph);
    virtual ~Glyph();

    Glyph(const Glyph& other) = delete;
    Glyph(Glyph&& other) noexcept;
    Glyph& operator =(const Glyph& other) = delete;
    Glyph& operator =(Glyph&& other) noexcept;

    virtual std::unique_ptr<Glyph> clone() const;

    int advance() const  {return m_glyph->advance.x >> 16;}
	int descent() const {return get_control_box().bottom();}
    
	GlyphFormat format() {return static_cast<GlyphFormat>(m_glyph->format);}

	BitmapGlyph make_bitmap_glyph(GlyphRenderMode render_mode) const;

	Rectanglei get_control_box() const;

protected:

    FT_Glyph m_glyph = nullptr;
private:
};

}

#endif
    

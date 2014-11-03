#ifndef FT_BITMAPGLYPH_H__
#define FT_BITMAPGLYPH_H__

#include "Glyph.h"

#include <memory>

#include "Enums.h"

namespace ft
{

class BitmapGlyph: public Glyph
{
public:
    explicit BitmapGlyph(FT_BitmapGlyph glyph);
    virtual ~BitmapGlyph();

    BitmapGlyph(const BitmapGlyph& other) = delete;
    BitmapGlyph(BitmapGlyph&& other) noexcept;
    BitmapGlyph& operator =(const BitmapGlyph& other) = delete;
    BitmapGlyph& operator =(BitmapGlyph&& other) noexcept;

    virtual std::unique_ptr<Glyph> clone() const override;

    int left() const {return bitmap_glyph()->left;}
	int top() const {return bitmap_glyph()->top;}

	int rows() const {return bitmap_glyph()->bitmap.rows;}
	int width() const {return bitmap_glyph()->bitmap.width;}
	int pitch() const {return bitmap_glyph()->bitmap.pitch;}

    short num_grays() const {return bitmap_glyph()->bitmap.num_grays;}

	PixelMode pixel_mode() const {return static_cast<PixelMode>(bitmap_glyph()->bitmap.pixel_mode);}

	const unsigned char* buffer() const {return bitmap_glyph()->bitmap.buffer;}

    static BitmapGlyph from_glyph(Glyph glyph, GlyphRenderMode render_mode);

protected:

    FT_BitmapGlyph bitmap_glyph() const {return reinterpret_cast<FT_BitmapGlyph>(m_glyph);}
private:
};

}

#endif
    

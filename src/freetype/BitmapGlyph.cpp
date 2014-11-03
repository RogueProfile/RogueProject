#include "BitmapGlyph.h"

#include "FreeTypeError.h"

namespace ft
{

BitmapGlyph::BitmapGlyph(FT_BitmapGlyph glyph):
    Glyph(&glyph->root)
{
}
 
BitmapGlyph::~BitmapGlyph()
{
 
}
 
BitmapGlyph::BitmapGlyph(BitmapGlyph&& other) noexcept:
    Glyph(std::move(other))
{
}
 
BitmapGlyph& BitmapGlyph::operator=(BitmapGlyph&& other) noexcept
{
    Glyph::operator =(std::move(other));
    return *this;
}
 
std::unique_ptr<Glyph> BitmapGlyph::clone() const
{
    FT_Glyph new_glyph;
    auto error = FT_Glyph_Copy(m_glyph, &new_glyph); 
    if(error != 0)
    {
        throw FreeTypeError("Unable to clone glyph", error);
    }
    return std::unique_ptr<BitmapGlyph>(
        new BitmapGlyph(reinterpret_cast<FT_BitmapGlyph>(new_glyph)));
}

BitmapGlyph BitmapGlyph::from_glyph(Glyph glyph, GlyphRenderMode render_mode)
{
    auto new_glyph = glyph.m_glyph;
    auto error = FT_Glyph_To_Bitmap(&new_glyph, static_cast<FT_Render_Mode>(render_mode),
          nullptr, true);
    if(error != 0)
    {
        throw FreeTypeError("Unable to convert glyph to a bitmap", error);
    }
    glyph.m_glyph = nullptr;
    return BitmapGlyph(reinterpret_cast<FT_BitmapGlyph>(new_glyph));
}
 
}
 


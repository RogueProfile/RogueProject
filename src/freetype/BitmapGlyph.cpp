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

}
 


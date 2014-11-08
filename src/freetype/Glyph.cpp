#include "Glyph.h"

#include "FreeTypeError.h"
#include "BitmapGlyph.h"

namespace ft
{

Glyph::Glyph(FT_Glyph glyph):
    m_glyph(glyph)
{
 
}

Glyph::~Glyph()
{
    destroy();
}

Glyph::Glyph(Glyph&& other) noexcept:
    m_glyph(other.m_glyph)
{
    other.m_glyph = nullptr; 
}
 
Glyph& Glyph::operator=(Glyph&& other) noexcept
{
    using std::swap;
    destroy();
    m_glyph = nullptr;
    swap(m_glyph, other.m_glyph);
    return *this;
}

std::unique_ptr<Glyph> Glyph::clone() const
{
    FT_Glyph new_glyph;
    auto error = FT_Glyph_Copy(m_glyph, &new_glyph); 
    if(error != 0)
    {
        throw FreeTypeError("Unable to clone glyph", error);
    }
    return std::unique_ptr<Glyph>(new Glyph(new_glyph));
}
 
Rectanglei Glyph::get_control_box() const
{
    FT_BBox bbox;
	FT_Glyph_Get_CBox(m_glyph, FT_GLYPH_BBOX_PIXELS, &bbox);
	return Rectanglei::from_vertices(bbox.xMin >> 6, -bbox.yMin >> 6, bbox.xMax >> 6, -bbox.yMax >> 6); 
}
 
BitmapGlyph Glyph::make_bitmap_glyph(GlyphRenderMode render_mode) const
{
    auto new_glyph = m_glyph;
    auto error = FT_Glyph_To_Bitmap(&new_glyph, static_cast<FT_Render_Mode>(render_mode),
          nullptr, false);
    if(error != 0)
    {
        throw FreeTypeError("Unable to convert glyph to a bitmap", error);
    }
    if(new_glyph == m_glyph)
    {
        throw FreeTypeError("Glyph could not be converted to a bitmap as "
            "it is either already a bitmap or it is not a scalar", 0);
    }
    return BitmapGlyph(reinterpret_cast<FT_BitmapGlyph>(new_glyph));
}
 
void Glyph::destroy()
{
    if(m_glyph != nullptr)
    {
        FT_Done_Glyph(m_glyph);
    } 
}
 
}


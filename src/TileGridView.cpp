#include "TileGridView.h"

#include "TileGrid.h"

TileGridView::TileGridView(TileGrid& parent, const Rectanglei& rect):
    m_parent(&parent), m_rect(rect)
{
 
}
 
size_t TileGridView::translate_index(int x, int y) const
{
    return (m_rect.left() + x + m_parent->width() * (y + m_rect.bottom()));
}

size_t TileGridView::translate_index(size_t index) const
{
    auto x = index % m_rect.width();
	auto y = index / m_rect.width();
    return translate_index(x, y);
}
 
const Tile& TileGridView::operator[](size_t index) const
{
    return m_parent->operator [](translate_index(index));
}
 
Tile& TileGridView::operator[](size_t index)
{
    return m_parent->operator [](translate_index(index));
}
 
const Tile& TileGridView::get_tile(int x, int y) const
{
    return m_parent->operator [](translate_index(x, y)); 
}
 
Tile& TileGridView::get_tile(int x, int y)
{
    return m_parent->operator [](translate_index(x, y)); 
}

const Tile& TileGridView::get_tile(size_t index) const
{
    return m_parent->operator [](translate_index(index)); 
}
 
Tile& TileGridView::get_tile(size_t index)
{
    return m_parent->operator [](translate_index(index)); 
}
 
void TileGridView::set_tile(size_t index, const Tile& tile)
{
    m_parent->operator[](translate_index(index)) = tile; 
}
 
void TileGridView::set_tile(int x, int y, const Tile& tile)
{
    m_parent->operator[](translate_index(x, y)) = tile; 
}
 
TileGridView& TileGridView::fill(Tile tile)
{
    for(auto x = 0; x < width();  ++x)
    {
        for(auto y = 0; y < height(); ++y)
        {
            m_parent->set_tile(translate_index(x, y), tile);
        }
    } 
    return *this;
}
 
TileGridView& TileGridView::fill_background_color(Color color)
{
    apply_to_all([color](Tile& t)
    {
        t.set_background_color(color);
    });
    return *this;
}
 
TileGridView& TileGridView::fill_foreground_color(Color color)
{
    apply_to_all([color](Tile& t)
    {
        t.set_foreground_color(color);
    });
    return *this;
}
 
TileGridView& TileGridView::fill_tile_index(unsigned int index)
{
 
    apply_to_all([index](Tile& t)
    {
        t.set_tile_index(index);
    });
    return *this;
}
 

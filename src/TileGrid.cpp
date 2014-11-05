#include "TileGrid.h"

#include "TileGridView.h"

TileGrid::TileGrid(int width, int height):
    m_width(width), m_height(height),
    m_tiles(width*height)
{
 
}
 
TileGridView TileGrid::default_view()
{
    return TileGridView(*this, Rectanglei(0, 0, m_width, m_height)); 
}

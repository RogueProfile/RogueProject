#ifndef TILEGRIDVIEW_H__
#define TILEGRIDVIEW_H__

#include <cstddef>

#include "Rectangle.h"

#include "Tile.h"

class TileGrid;

class TileGridView
{
public:
    TileGridView(TileGrid& parent, const Rectanglei& rect);
    TileGridView(const TileGridView& parent, Rectanglei rect);
    ~TileGridView() = default;

    TileGridView(const TileGridView& other) = default;
    TileGridView(TileGridView&& other) noexcept = default;
    TileGridView& operator =(const TileGridView& other) = default;
    TileGridView& operator =(TileGridView&& other) noexcept = default;

    const Tile& operator [](size_t index) const;
    Tile& operator [](size_t index);

    int width() const {return m_rect.width();}
    int height() const {return m_rect.height();}

    void fill(const Tile& tile);

    const Rectanglei bounds() const {return m_rect;}

protected:
    size_t translate_index(int x, int y) const;
    size_t translate_index(size_t index) const;

    TileGrid* m_parent;
    Rectanglei m_rect;
private:
};

 
#endif
    

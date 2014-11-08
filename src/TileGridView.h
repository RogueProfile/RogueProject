#ifndef TILEGRIDVIEW_H__
#define TILEGRIDVIEW_H__

#include <cstddef>

#include "Rectangle.h"

#include "Tile.h"
#include "Color.h"

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

    const Tile& get_tile(int x, int y) const;
    const Tile& get_tile(size_t index) const;
    Tile& get_tile(int x, int y);
    Tile& get_tile(size_t index);
    void set_tile(size_t index, const Tile& tile);
    void set_tile(int x, int y, const Tile& tile);

    int width() const {return m_rect.width();}
    int height() const {return m_rect.height();}

    int tile_count() const {return width() * height();}

    TileGridView& fill(Tile tile);
    TileGridView& fill_background_color(Color color);
    TileGridView& fill_foreground_color(Color color);
    TileGridView& fill_tile_index(unsigned int index);

    const Rectanglei bounds() const {return m_rect;}

    TileGrid* parent() {return m_parent;}
    const TileGrid* parent() const {return m_parent;}

    template<typename FnType>
    void apply_to_all(const FnType& fn);

    template<typename FnType>
    void apply_to_line(int x1, int y1, int x2, int y2, const FnType& fn);
    template<typename FnType>
    void apply_to_line(const Vector2i& start, const Vector2i& end, const FnType& fn)
    {
        apply_to_line(start.x, start.y, end.x, end.y, fn);
    }

    template<typename FnType>
    void apply_to_box(int x, int y, int width, int height, const FnType& fn);
    template<typename FnType>
    void apply_to_box(const Rectanglei& box, const FnType& fn)
    {
        apply_to_box(box.left(), box.bottom(), box.width(), box.height(), fn);
    }

protected:
    size_t translate_index(int x, int y) const;
    size_t translate_index(size_t index) const;

    TileGrid* m_parent;
    Rectanglei m_rect;
private:
};

 
template<typename FnType>
inline void TileGridView::apply_to_all(const FnType& fn)
{
    for(auto y = 0; y < height(); ++y)
    {
        for(auto x = 0; x < width(); ++x)
        {
            fn(get_tile(x, y));
        }
    } 
}
 
template<typename FnType>
inline void TileGridView::apply_to_line(int x1, int y1, int x2, int y2, const FnType& fn)
{
    auto dx = std::abs(x2 - x1);
    auto dy = std::abs(y2 - y1);
    auto sx = (x1 < x2 ? 1 : -1);
    int sy = (y1 < y2 ? 1 : -1);

    int error = dx - dy;

    while(x1 > 0 && x1 < width() && y1 > 0 && y1 < height())
    {
        fn(get_tile(x1, y1));
        if(x1 == x2 && y1 == y2)
        {
            break;
        }
        int e2 = 2 * error;
        if(e2 > -dy)
        {
            error -= dy;
            x1 += sx;
        }
        if(e2 < dx)
        {
            error += dx;
            y1 += sy;
        }
    }
}
 
template<typename FnType>
inline void TileGridView::apply_to_box(int x, int y, int width, int height, const FnType& fn)
{
    for(auto y_pos = y; y_pos < height + y; ++y_pos)
    {
        if(y_pos >= m_rect.height())
        {
            break;
        }
        for(auto x_pos = x; x_pos < width + x; ++x_pos)
        {
            if(x_pos >= m_rect.width())
            {
                break;
            }
            fn(get_tile(x, y));
        }
    }
}
 
#endif

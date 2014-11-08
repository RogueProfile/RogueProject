#ifndef TILEGRID_H__
#define TILEGRID_H__

#include <vector>
#include <cstddef>

#include "Tile.h"

class TileGridView;

class TileGrid
{
public:
    TileGrid(int width, int height);
    ~TileGrid() = default;

    TileGrid(const TileGrid& other) = default;
    TileGrid(TileGrid&& other) noexcept = default;
    TileGrid& operator =(const TileGrid& other) = default;
    TileGrid& operator =(TileGrid&& other) noexcept = default;

    const Tile& operator [](size_t index) const {return m_tiles[index];}
    Tile& operator [](size_t index) {return m_tiles[index];}

    const Tile& get_tile(size_t index) const {return operator [](index);}
    const Tile& get_tile(int x, int y) const {return m_tiles[x + m_width * y];}
    Tile& get_tile(size_t index) {return operator [](index);}
    Tile& get_tile(int x, int y) {return m_tiles[x + m_width * y];}
    void set_tile(size_t index, const Tile& tile) {m_tiles[index] = tile;}
    void set_tile(int x, int y, const Tile& tile) {m_tiles[x + m_width * y] = tile;}

    int width() const {return m_width;}
    int height() const {return m_height;}

    TileGridView default_view();

protected:
    std::vector<Tile> m_tiles; 

    int m_width;
    int m_height;
private:
};


#endif
    

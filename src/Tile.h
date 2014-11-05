#ifndef TILE_H__
#define TILE_H__

#include "Color.h"

class Tile
{
public:
    Tile() {};
    Tile(const Color& fg_color, const Color& bg_color, 
        unsigned int tile_index);
    ~Tile() = default;

    Tile(const Tile& other) = default;
    Tile(Tile&& other) noexcept = default;
    Tile& operator =(const Tile& other) = default;
    Tile& operator =(Tile&& other) noexcept = default;

    const Color& foreground_color() const {return m_fg_color;}
    Color& foreground_color() {return m_fg_color;}
    void set_foreground_color(const Color& value) {m_fg_color = value;}
    const Color& background_color() const {return m_bg_color;}
    Color& background_color() {return m_bg_color;}
    void set_background_color(const Color& value) {m_bg_color = value;}

    unsigned int tile_index() const {return m_tile_index;}
    void set_tile_index(unsigned int value) {m_tile_index = value;}

protected:
    Color m_fg_color = Color::white();
    Color m_bg_color = Color::black();
    unsigned int m_tile_index = ' '; 
private:
};


#endif
    

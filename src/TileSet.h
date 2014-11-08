#ifndef TILESET_H__
#define TILESET_H__

#include "Vector2.h"

namespace gl
{
    class Texture;
}

class TileSet
{
public:
    enum class TextureType
    {
        Texture2d,
        Texture2dArray
    };

    struct TileLocation
    {
        Vector2f bottom_left;
        Vector2f top_right;

        int layer;
        int vertical_offset;
    };


    TileSet() = default;
    virtual ~TileSet() = default;

    TileSet(const TileSet& other) = delete;
    TileSet(TileSet&& other) noexcept = default;
    TileSet& operator =(const TileSet& other) = delete;
    TileSet& operator =(TileSet&& other) noexcept = default;

    virtual int tile_width() const = 0;
    virtual int tile_height() const = 0;

    virtual const TileLocation& get_tile_location(unsigned int id) = 0;

    virtual gl::Texture* get_texture() = 0;

protected:
private:
};


#endif
    

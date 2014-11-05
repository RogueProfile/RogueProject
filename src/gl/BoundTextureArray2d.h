#ifndef GL_BOUNDTEXTUREARRAY2D_H__
#define GL_BOUNDTEXTUREARRAY2D_H__

#include "TextureArray2d.h"
#include "TargetLock.h"

#include "Rectangle.h"

namespace gl
{

class BoundTextureArray2d
{
public:
    BoundTextureArray2d(TextureArray2d* texture,
            TargetLock lock);
    ~BoundTextureArray2d();

    BoundTextureArray2d(const BoundTextureArray2d& other) = delete;
    BoundTextureArray2d(BoundTextureArray2d&& other) noexcept;
    BoundTextureArray2d& operator =(const BoundTextureArray2d& other) = delete;
    BoundTextureArray2d& operator =(BoundTextureArray2d&& other);

    void set_clamp_mode(Texture::ClampMode clamp_s, Texture::ClampMode clamp_t);
    void set_filter_modes(Texture::FilterMode mag_filter, Texture::FilterMode min_filter);

    void update_data(const Rectanglei& update_region, int start_layer,
            int stop_layer, Texture::DataPixelFormat data_format,
            Texture::PixelType pixel_type, const void* data);

    void generate_mipmap();

    TextureArray2d* get_texture() {return m_texture;}

protected:

    TextureArray2d* m_texture;
    TargetLock m_lock;
private:
};

}

#endif
    

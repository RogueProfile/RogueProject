#ifndef GL_BOUNDTEXTURE2D_H__
#define GL_BOUNDTEXTURE2D_H__

#include <vector>

#include "Texture2d.h"
#include "TargetLock.h"

#include "GlMacros.h"
#include "GlError.h"

#include "Rectangle.h"

namespace gl
{

class BoundTexture2d
{
public:
    BoundTexture2d(Texture2d* texture,
            TargetLock lock);
    ~BoundTexture2d() = default;

    BoundTexture2d(const BoundTexture2d& other) = delete;
    BoundTexture2d(BoundTexture2d&& other) noexcept;
    BoundTexture2d& operator =(const BoundTexture2d& other) = delete;
    BoundTexture2d& operator =(BoundTexture2d&& other) noexcept = default;

    void set_clamp_mode(Texture::ClampMode clamp_s, Texture::ClampMode clamp_t);
    void set_filter_modes(Texture::FilterMode mag_filter, Texture::FilterMode min_filter);

    void update_data(const Rectanglei& update_region, Texture::DataPixelFormat pixel_format,
            Texture::PixelType pixel_type, const void* data);

    void generate_mipmap();

    template<typename T>
    std::vector<T> read_pixel_data(int mipmap_level,
            Texture::DataPixelFormat pixel_format,
            Texture::PixelType pixel_type);

    Texture2d* get_texture() {return m_texture;}

protected:

    Texture2d* m_texture;
    TargetLock m_lock;
private:
};

template<typename T>
std::vector<T> BoundTexture2d::read_pixel_data(int mipmap_level,
       Texture::DataPixelFormat pixel_format, Texture::PixelType pixel_type)
{
    auto data_size = m_texture->width() * m_texture->height() 
        * Texture::pixel_size_for_format(pixel_format, pixel_type);
    auto data = std::vector<T>(data_size / sizeof(T));
    glGetTexImage(GL_TEXTURE_2D, mipmap_level, static_cast<GLenum>(pixel_format),
           static_cast<GLenum>(pixel_type), data.data());
    CHECK_GL_ERROR(glGetTextImage);
    return data;
}

}

#endif

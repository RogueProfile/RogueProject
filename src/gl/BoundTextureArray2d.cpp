#include "BoundTextureArray2d.h"

#include "GlMacros.h"
#include "GlError.h"
#include "Exceptions/EnumValueError.h"

namespace gl
{

BoundTextureArray2d::BoundTextureArray2d(TextureArray2d* texture, TargetLock lock):
    m_texture(texture), m_lock(std::move(lock))
{
 
}
 
BoundTextureArray2d::~BoundTextureArray2d()
{
 
}
 
BoundTextureArray2d::BoundTextureArray2d(BoundTextureArray2d&& other) noexcept:
    m_texture(other.m_texture), m_lock(std::move(other.m_lock))
{
    other.m_texture = nullptr; 
}
 
BoundTextureArray2d& BoundTextureArray2d::operator=(BoundTextureArray2d&& other)
{
    m_texture = nullptr;
    std::swap(m_texture, other.m_texture);
    m_lock = std::move(other.m_lock);
    return *this; 
}
 
void BoundTextureArray2d::set_clamp_mode(Texture::ClampMode clamp_s, Texture::ClampMode clamp_t)
{
    glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, static_cast<GLenum>(clamp_s));
	CHECK_GL_ERROR(glTexParameterf);
	glTexParameterf(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, static_cast<GLenum>(clamp_t));
	CHECK_GL_ERROR(glTexParameterf); 
}
 
void BoundTextureArray2d::set_filter_modes(Texture::FilterMode mag_filter, Texture::FilterMode min_filter)
{
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLenum>(min_filter));
	CHECK_GL_ERROR(glTexParameteri);
	if(mag_filter != Texture::FilterMode::Linear 
            && mag_filter != Texture::FilterMode::Nearest)
	{
		throw EnumValueError("FilterMode",
            "Texture magnification filter does not support mipmap functions");
	}
	else
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLenum>(mag_filter));
		CHECK_GL_ERROR(glTexParameteri);
	} 
}
 
void BoundTextureArray2d::update_data(const Rectanglei& update_region,
    int start_layer, int stop_layer,
    Texture::DataPixelFormat data_format, Texture::PixelType pixel_type,
    const void* data)
{     
    glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, update_region.left(), update_region.bottom(), start_layer,
			update_region.width(), update_region.height(), stop_layer,
            static_cast<GLenum>(data_format), static_cast<GLenum>(pixel_type), data);
    CHECK_GL_ERROR(glTexSubImage3D);
}
 
void BoundTextureArray2d::generate_mipmap()
{
    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
    CHECK_GL_ERROR(glGenerateMipmap);
}
 
}

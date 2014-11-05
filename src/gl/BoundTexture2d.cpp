#include "BoundTexture2d.h"

#include <utility>

#include "Exceptions/EnumValueError.h"

namespace gl
{

BoundTexture2d::BoundTexture2d(Texture2d* texture, TargetLock lock):
    m_texture(texture), m_lock(std::move(lock))
{
}

void BoundTexture2d::set_clamp_mode(Texture::ClampMode clamp_s, Texture::ClampMode clamp_t)
{
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLenum>(clamp_s));
	CHECK_GL_ERROR(glTexParameterf);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLenum>(clamp_t));
	CHECK_GL_ERROR(glTexParameterf); 
}
 
void BoundTexture2d::update_data(const Rectanglei& update_region,
        Texture::DataPixelFormat data_format, Texture::PixelType pixel_type, const void* data)
{
     glTexSubImage2D(GL_TEXTURE_2D, 0, update_region.left(), update_region.bottom(),
			update_region.width(), update_region.height(), static_cast<GLenum>(data_format),
			static_cast<GLenum>(pixel_type), data);
	CHECK_GL_ERROR(glTexSubImage2D);
}
 
void BoundTexture2d::set_filter_modes(Texture::FilterMode mag_filter,
        Texture::FilterMode min_filter)
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
 
void BoundTexture2d::generate_mipmap()
{
    glGenerateMipmap(GL_TEXTURE_2D);
    CHECK_GL_ERROR(glGenerateMipmap);
}

 
}

 

#include "Texture2d.h"

#include <cmath>
#include <algorithm>

#include "GlMacros.h"
#include "GlError.h"
#include "GlContext.h"

namespace gl
{

Texture2d::Texture2d(GlContext* ctx, int width, int height,
       int mipmap_levels, InternalPixelFormat format):
    m_width(width), m_height(height), m_pixel_format(format)
{
    glGenTextures(1, &m_handle); 
    CHECK_GL_ERROR(glGenTextures);

    glBindTexture(GL_TEXTURE_2D, m_handle);
    CHECK_GL_ERROR(glBindTexture);

    initialize_params_to_default();
    allocate_mipmap_storage(mipmap_levels, format);
    ctx->rebind_texture_2d();
}
 
Texture2d::~Texture2d()
{
    destroy(); 
}
 
Texture2d::Texture2d(Texture2d&& other) noexcept:
    Texture(std::move(other)),
    m_width(other.m_width), m_height(other.m_height),
    m_pixel_format(other.m_pixel_format)
{
}
 
Texture2d& Texture2d::operator=(Texture2d&& other) noexcept
{
    destroy();
    m_handle = NullHandle;
    std::swap(m_handle, other.m_handle);
    m_width = other.m_width;
    m_height = other.m_height;
    m_pixel_format = other.m_pixel_format;
    return *this;
}
 
void Texture2d::initialize_params_to_default()
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	CHECK_GL_ERROR(glTexParameteri);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	CHECK_GL_ERROR(glTexParameteri);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	CHECK_GL_ERROR(glTexParameteri);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	CHECK_GL_ERROR(glTexParameteri);
}
 
void Texture2d::allocate_mipmap_storage(int mipmap_levels, InternalPixelFormat format)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, mipmap_levels);
	CHECK_GL_ERROR(glTexParameteri);

#if GL_TARGET_VERSION >= 402
	//Use immutable storage if available
	glTexStorage2D(GL_TEXTURE_2D, mipmapLevels, static_cast<GLenum>(format),
			m_width, m_height);
	CHECK_GL_ERROR(glTexStorage2D);
#else
	auto level_width = m_width;
	auto level_height = m_height;
	for(auto i = 0; i < mipmap_levels; ++i)
	{
		glTexImage2D(GL_TEXTURE_2D, i, static_cast<GLenum>(format), level_width, level_height, 0,
				GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, nullptr);
		CHECK_GL_ERROR(glTexImage2D);
		if(level_width == 1 && level_height == 1)
		{
			break;
		}
		level_width = std::max(1, level_width / 2);
		level_height = std::max(1, level_height / 2);
	}
#endif
}
 
void Texture2d::destroy()
{
    if(m_handle != NullHandle)
    {
        glDeleteTextures(1, &m_handle);
    }
}
 
}


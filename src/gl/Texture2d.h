#ifndef GL_TEXTURE2D_H__
#define GL_TEXTURE2D_H__

#include "Texture.h"

namespace gl
{

class Texture2d: public Texture
{
    friend class GlContext;
public:
    
    virtual ~Texture2d();

    Texture2d(const Texture2d& other) = delete;
    Texture2d(Texture2d&& other) noexcept;
    Texture2d& operator =(const Texture2d& other) = delete;
    Texture2d& operator =(Texture2d&& other) noexcept;

    int width() const {return m_width;}
    int height() const {return m_height;}

protected:
    Texture2d(int width, int height, int mipmap_levels,
            InternalPixelFormat format);

    void initialize_params_to_default();
    void allocate_mipmap_storage(int mipmap_levels, InternalPixelFormat format);
    virtual void destroy() override;

    int m_width;
    int m_height;
private:
};

}

#endif
    

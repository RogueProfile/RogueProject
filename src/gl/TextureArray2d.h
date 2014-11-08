#ifndef GL_TEXTUREARRAY2D_H__
#define GL_TEXTUREARRAY2D_H__

#include "Texture.h"

namespace gl
{
class GlContext;

class TextureArray2d: public Texture
{
    friend class GlContext;
public:
    TextureArray2d(GlContext* ctx, int width, int height, int num_layers,
            int mipmap_levels, InternalPixelFormat format);
    ~TextureArray2d();

    TextureArray2d(const TextureArray2d& other) = default;
    TextureArray2d(TextureArray2d&& other) noexcept;
    TextureArray2d& operator =(const TextureArray2d& other) = default;
    TextureArray2d& operator =(TextureArray2d&& other) noexcept;

    int width() const {return m_width;}
    int height() const {return m_height;}
    int num_layers() const {return m_num_layers;}

protected:

    virtual void destroy() override;

    void initialize_params_to_default();
    void allocate_mipmap_storage(int mipmap_levels, InternalPixelFormat format);

    int m_width;
    int m_height;
    int m_num_layers;
private:
};

}

#endif
    

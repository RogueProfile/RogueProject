#ifndef GL_GLOBJECT_H__
#define GL_GLOBJECT_H__

#include "GlHeaders.h"

namespace gl
{

class GlObject
{
public:
    static constexpr GLuint NullHandle = 0;

    virtual ~GlObject() = default;

    GlObject(const GlObject& other) = delete;
    GlObject(GlObject&& other) noexcept;
    GlObject& operator =(const GlObject& other) = delete;
    GlObject& operator =(GlObject&& other) noexcept;

    GLuint handle() const {return m_handle;}

protected:
    virtual void destroy() = 0;

    GlObject() = default;
    GlObject(GLuint handle);
    GLuint m_handle = NullHandle;
};

}

#endif
    

#ifndef GL_TARGETBINDERROR_H__
#define GL_TARGETBINDERROR_H__

#include "Exceptions/Exception.h"


namespace gl
{

enum class Target
{
    ShaderProgram,
    Buffer,
    VertexArray,
    TextureArray2d
};


class TargetBindError: public Exception
{
public:
    TargetBindError(Target target);
    virtual ~TargetBindError() = default;

    TargetBindError(const TargetBindError& other);
    TargetBindError(TargetBindError&& other) noexcept;
    TargetBindError& operator =(const TargetBindError& other);
    TargetBindError& operator =(TargetBindError&& other) noexcept;

    Target target() const {return m_target;}

protected:
    Target m_target;
private:
};

}

std::ostream& operator <<(std::ostream& stream, gl::Target target);

#endif
    

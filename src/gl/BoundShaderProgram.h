#ifndef GL_BOUNDSHADERPROGRAM_H__
#define GL_BOUNDSHADERPROGRAM_H__

#include "ShaderProgram.h"
#include "TargetLock.h"

namespace gl
{

class BoundShaderProgram
{
public:
    BoundShaderProgram(ShaderProgram* object,
        TargetLock lock);
    ~BoundShaderProgram() = default;

    BoundShaderProgram(const BoundShaderProgram& other) = delete;
    BoundShaderProgram(BoundShaderProgram&& other) noexcept;
    BoundShaderProgram& operator =(const BoundShaderProgram& other) = delete;
    BoundShaderProgram& operator =(BoundShaderProgram&& other) noexcept;

protected:
    
    ShaderProgram* m_object = nullptr;
    TargetLock m_lock;
private:
};

}

#endif
    

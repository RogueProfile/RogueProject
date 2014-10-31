#ifndef GL_SHADER_H__
#define GL_SHADER_H__

#include "GlObject.h"

#include "GlHeaders.h"

#include <string>

namespace gl
{

enum class ShaderType: GLenum
{
    Vertex = GL_VERTEX_SHADER,
    Fragment = GL_FRAGMENT_SHADER 
};

class Shader: public GlObject
{
public:
    Shader(ShaderType type);
    virtual ~Shader() override;

    Shader(const Shader& other) = delete;
    Shader(Shader&& other) noexcept;
    Shader& operator =(const Shader& other) = delete;
    Shader& operator =(Shader&& other) noexcept;

    void compile_source(const std::string& source);
    bool is_compiled() const;

    std::string get_info_log() const;

    ShaderType type() const {return m_type;}

protected:
    virtual void destroy() override;

    ShaderType m_type;
};

}

#endif
    

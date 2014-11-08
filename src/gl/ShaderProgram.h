#ifndef GL_SHADERPROGRAM_H__
#define GL_SHADERPROGRAM_H__

#include "GlObject.h"

#include <memory>
#include <string>
#include <vector>

#include "Shader.h"

namespace gl
{

class ShaderProgram: public GlObject
{
public:
    ShaderProgram();
    virtual ~ShaderProgram();

    ShaderProgram(const ShaderProgram& other) = delete;
    ShaderProgram(ShaderProgram&& other) noexcept;
    ShaderProgram& operator =(const ShaderProgram& other) = delete;
    ShaderProgram& operator =(ShaderProgram&& other) noexcept;

    std::string get_info_log() const;

    void attach_shader(const Shader& new_shader);
    void link();

    void bind_attribute_location(const char* name, int location);
    void bind_attribute_location(const std::string& name, int location)
        {bind_attribute_location(name.c_str(), location);}

    int get_attribute_location(const char* name) const;
    int get_attribute_location(const std::string& name) const
        {return get_attribute_location(name.c_str());}

    int get_uniform_location(const char* name) const;
    int get_uniform_location(const std::string& name) const
        {return get_uniform_location(name.c_str());}


protected:
    virtual void destroy() override;
    
private:
};

}

#endif

#include "Shader.h"

#include <memory>

#include "GlError.h"
#include "GlMacros.h"

#include "ShaderCompilationError.h"

namespace gl
{

Shader::Shader(ShaderType type):
    GlObject(glCreateShader(static_cast<GLenum>(type))),
    m_type(type)
{
    CHECK_GL_ERROR(glCreateShader);
}

Shader::~Shader()
{
    destroy(); 
}
 
Shader::Shader(Shader&& other) noexcept:
    GlObject(std::move(other)),
    m_type(other.m_type)
{
}
 
Shader& Shader::operator=(Shader&& other) noexcept
{
    GlObject::operator=(std::move(other));
    m_type = other.m_type;
    return *this; 
}
 
void Shader::compile_source(const std::string& source)
{
    auto size = static_cast<GLint>(source.size());
    auto text = source.c_str();
    glShaderSource(m_handle, 1, &text, &size);
    CHECK_GL_ERROR(glShaderSource);
    glCompileShader(m_handle);
    CHECK_GL_ERROR(glCompileShader); 
    if(!is_compiled())
    {
        throw ShaderCompilationError(get_info_log());
    }
}
 
bool Shader::is_compiled() const
{
    auto out = GL_FALSE;
    glGetShaderiv(m_handle, GL_COMPILE_STATUS, &out);
    CHECK_GL_ERROR(glGetShaderiv);
    return (out == GL_TRUE);  
}
 
std::string Shader::get_info_log() const
{
    auto length = 0;
	glGetShaderiv(m_handle, GL_INFO_LOG_LENGTH, &length);
	CHECK_GL_ERROR(glGetShaderiv);

	std::string logText;
	if(length > 0)
	{
		auto text = std::unique_ptr<char []>(new char[length]);
		auto charsCopied = 0;
		glGetShaderInfoLog(m_handle, length, &charsCopied, text.get());
		CHECK_GL_ERROR(glGetShaderInfoLog);
		logText = text.get();
	}
	return logText; 
}
 
void Shader::destroy()
{
    if(m_handle != NullHandle)
    {
        glDeleteShader(m_handle); 
    }
}
 
}


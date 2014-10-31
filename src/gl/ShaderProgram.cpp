#include "ShaderProgram.h"

#include "GlException.h"
#include "GlHeaders.h"
#include "GlMacros.h"

namespace gl
{

ShaderProgram::ShaderProgram():
    GlObject(glCreateProgram())
{
    CHECK_GL_ERROR(glCreateProgram);
}
 
ShaderProgram::~ShaderProgram()
{
    destroy(); 
}
 
ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept:
    GlObject(std::move(other)),
    m_shaders(std::move(other.m_shaders))
{
}
 
ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept
{
    GlObject::operator=(std::move(other));
    m_shaders = std::move(other.m_shaders); 
    return *this;
}
 
std::string ShaderProgram::get_info_log() const
{
    auto length = 0;
	glGetProgramiv(m_handle, GL_INFO_LOG_LENGTH, &length);
	CHECK_GL_ERROR(glGetProgramiv);
	std::string logText;

	if(length > 0)
	{
		auto text = std::unique_ptr<char []>(new char[length]);
		int charsCopied = 0;
		glGetProgramInfoLog(m_handle, length, &charsCopied, text.get());
		CHECK_GL_ERROR(glGetProgramInfoLog);
		logText = text.get();
	}
	return logText;
}
 
void ShaderProgram::attach_shader(std::shared_ptr<Shader> new_shader)
{
    glAttachShader(m_handle, new_shader->handle()); 
    CHECK_GL_ERROR(glAttachShader);
    m_shaders.push_back(std::move(new_shader));
}
 
void ShaderProgram::link()
{
    glLinkProgram(m_handle);
    CHECK_GL_ERROR(glLinkProgram); 
}
 
void ShaderProgram::bind_attribute_location(const char* name, int location)
{
    glBindAttribLocation(m_handle, location, name); 
    CHECK_GL_ERROR(glBindAttribLocation);
}
 
int ShaderProgram::get_attribute_location(const char* name) const
{
    auto location = glGetAttribLocation(m_handle, name); 
    CHECK_GL_ERROR(glGetAttributeLocation);
    return location;
}
 
int ShaderProgram::get_uniform_location(const char* name) const
{
    auto location = glGetUniformLocation(m_handle, name);
    CHECK_GL_ERROR(glGetUniformLocation);
    return location; 
}
 
void ShaderProgram::destroy()
{
    if(m_handle != NullHandle)
    {
        glDeleteProgram(m_handle);     
    } 
}
 
}


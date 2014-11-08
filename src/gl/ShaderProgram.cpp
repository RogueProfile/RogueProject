#include "ShaderProgram.h"

#include "GlError.h"
#include "GlHeaders.h"
#include "GlMacros.h"

#include "ShaderCompilationError.h"

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
    GlObject(std::move(other))
{
}
 
ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept
{
    GlObject::operator=(std::move(other));
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
 
void ShaderProgram::attach_shader(const Shader& new_shader)
{
    glAttachShader(m_handle, new_shader.handle()); 
    CHECK_GL_ERROR(glAttachShader);
}
 
void ShaderProgram::link()
{
    glLinkProgram(m_handle);
    CHECK_GL_ERROR(glLinkProgram); 
    if(!is_linked())
    {
        throw ShaderCompilationError(get_info_log());
    }
}
 
bool ShaderProgram::is_linked() const
{
    int is_linked = 0;
    glGetProgramiv(m_handle, GL_LINK_STATUS, &is_linked); 
    CHECK_GL_ERROR(glGetProgramiv); 
    return is_linked != 0;
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


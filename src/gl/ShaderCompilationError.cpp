#include "ShaderCompilationError.h"

namespace gl
{

ShaderCompilationError::ShaderCompilationError(std::string info_log):
    m_info_log(std::move(info_log))
{
    set_message("Shader compilation failed:\n" + m_info_log); 
}
 
ShaderCompilationError::ShaderCompilationError(const gl::ShaderCompilationError& other):
    Exception(other),
    m_info_log(other.m_info_log)
{
}
 
ShaderCompilationError::ShaderCompilationError(gl::ShaderCompilationError&& other) noexcept:
    Exception(std::move(other)),
    m_info_log(std::move(other.m_info_log))
{
}
 
ShaderCompilationError& ShaderCompilationError::operator=(const gl::ShaderCompilationError& other)
{
    m_message = other.m_message;
    m_info_log = other.m_info_log;
    return *this; 
}
 
ShaderCompilationError& ShaderCompilationError::operator=(gl::ShaderCompilationError&& other) noexcept
{
    m_message = std::move(other.m_message);
    m_info_log = std::move(other.m_info_log);
    return *this; 
}
 
}


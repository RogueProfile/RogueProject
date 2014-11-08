#ifndef GL_SHADERCOMPILATIONERROR_H__
#define GL_SHADERCOMPILATIONERROR_H__

#include "Exceptions/Exception.h"

#include <string>

namespace gl
{

class ShaderCompilationError: public Exception
{
public:
    ShaderCompilationError(std::string info_log);
    virtual ~ShaderCompilationError() = default;

    ShaderCompilationError(const ShaderCompilationError& other);
    ShaderCompilationError(ShaderCompilationError&& other) noexcept;
    ShaderCompilationError& operator =(const ShaderCompilationError& other);
    ShaderCompilationError& operator =(ShaderCompilationError&& other) noexcept;

    const std::string& info_log() const {return m_info_log;}

protected:

    std::string m_info_log;
private:
};

}

#endif
    

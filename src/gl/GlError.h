#ifndef GL_GLERROR_H__
#define GL_GLERROR_H__

#include "Exceptions/Exception.h"

#include "GlHeaders.h"

#include <string>

namespace gl
{

class GlError: public Exception
{
public:
    GlError(const std::string& function, GLenum error_code);
    virtual ~GlError() = default;

    GlError(const GlError& other);
    GlError(GlError&& other) noexcept;
    GlError& operator =(const GlError& other);
    GlError& operator =(GlError&& other) noexcept;

    GLenum error_code() const {return m_error_code;}

protected:
    GLenum m_error_code;
private:
};

}

#endif
    

#ifndef GL_GLEXCEPTION_H__
#define GL_GLEXCEPTION_H__

#include "Exceptions/Exception.h"

#include "GlHeaders.h"

#include <string>

namespace gl
{

class GlException: public Exception
{
public:
    GlException(const std::string& function, GLenum error_code);
    virtual ~GlException() = default;

    GlException(const GlException& other);
    GlException(GlException&& other) noexcept;
    GlException& operator =(const GlException& other);
    GlException& operator =(GlException&& other) noexcept;

    GLenum error_code() const {return m_error_code;}

protected:
    GLenum m_error_code;
private:
};

}

#endif
    

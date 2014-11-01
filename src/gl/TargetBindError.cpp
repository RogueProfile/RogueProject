#include "TargetBindError.h"

#include <ostream>
#include <sstream>

namespace gl
{

TargetBindError::TargetBindError(Target target):
    m_target(target)
{
    std::ostringstream stream;
    stream << "Unable to bind GL object to target '"
        << target << "'";
    set_message(stream.str());
}

 
TargetBindError::TargetBindError(const TargetBindError& other):
    Exception(other), 
    m_target(other.m_target)
{
}
 
TargetBindError::TargetBindError(TargetBindError&& other) noexcept:
    Exception(std::move(other)), 
    m_target(other.m_target)
{
}
 
TargetBindError& TargetBindError::operator=(const TargetBindError& other)
{
    Exception::operator =(other);
    m_target = other.m_target;
    return *this;
}
 
TargetBindError& TargetBindError::operator=(TargetBindError&& other) noexcept
{
    Exception::operator =(std::move(other));
    m_target = other.m_target;
    return *this;
}
 
}

std::ostream& operator <<(std::ostream& stream, gl::Target target)
{
    switch(target)
    {
    case gl::Target::ShaderProgram: stream << "shader program"; break;
    case gl::Target::VertexBuffer: stream << "vertex buffer"; break;
    case gl::Target::IndexBuffer: stream << "index buffer"; break;
    }
    return stream;
}

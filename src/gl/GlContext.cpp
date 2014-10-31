#include "GlContext.h"

#include <iostream>

namespace gl
{

void GlContext::clear(const Flags<ClearTarget>& buffers)
{
    glClear(buffers.get_raw_value()); 
}

}

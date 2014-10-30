#include "GlContext.h"

#include <iostream>

void GlContext::clear(const Flags<ClearTarget>& buffers)
{
    glClear(buffers.get_raw_value()); 
}
 
 

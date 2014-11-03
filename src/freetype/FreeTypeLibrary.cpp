#include "FreeTypeLibrary.h"

namespace ft
{

FreeTypeLibrary::FreeTypeLibrary()
{
    FT_Init_FreeType(&m_library); 
}
 
FreeTypeLibrary::~FreeTypeLibrary()
{
    destroy();
}
 
FreeTypeLibrary::FreeTypeLibrary(FreeTypeLibrary&& other) noexcept:
    m_library(other.m_library)
{
    other.m_library = nullptr; 
}
 
FreeTypeLibrary& FreeTypeLibrary::operator=(FreeTypeLibrary&& other) noexcept
{
    destroy();
    m_library = other.m_library;
    other.m_library = nullptr;
    return *this; 
}
 
void FreeTypeLibrary::destroy()
{
    if(m_library != nullptr)
    {
        FT_Done_FreeType(m_library);
    }
}
 
}


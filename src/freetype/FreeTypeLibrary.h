#ifndef FT_FREETYPELIBRARY_H__
#define FT_FREETYPELIBRARY_H__

#include <ft2build.h>
#include FT_FREETYPE_H

namespace ft
{

class FreeTypeLibrary
{
public:
    FreeTypeLibrary();
    ~FreeTypeLibrary();

    FreeTypeLibrary(const FreeTypeLibrary& other) = delete;
    FreeTypeLibrary(FreeTypeLibrary&& other) noexcept;
    FreeTypeLibrary& operator =(const FreeTypeLibrary& other) = delete;
    FreeTypeLibrary& operator =(FreeTypeLibrary&& other) noexcept;

protected:
    void destroy();

    FT_Library m_library = nullptr;
private:
};

}

#endif
    

#include "FontManager.h"

#include <boost/filesystem/fstream.hpp>

#include "FontFace.h"

#include <iostream>

namespace ft
{

FontManager::FontManager(boost::filesystem::path root_directory):
    m_root_directory(std::move(root_directory))
{
    std::cout << m_root_directory << std::endl; 
}

FontManager::FontManager(FontManager&& other) noexcept:
    m_font_data(std::move(other.m_font_data)),
    m_font_faces(std::move(other.m_font_faces)), m_library(std::move(other.m_library)),
    m_root_directory(std::move(other.m_root_directory))
{
}

FontManager& FontManager::operator=(FontManager&& other) noexcept
{
    m_font_data = std::move(other.m_font_data);
    m_font_faces = std::move(other.m_font_faces); 
    m_library = std::move(other.m_library);
    m_root_directory = std::move(other.m_root_directory);
    return *this;
}
 
std::shared_ptr<const FontFace> FontManager::get_font_face(const std::string& name,
        int width, int height, Flags<GlyphLoadFlags> flags, int face_index)
{
    std::shared_ptr<const FontFace> out_face;
    FontFaceParams params(name, width, height, face_index, flags);

    auto it = m_font_faces.find(params);
    bool found = (it != m_font_faces.end());

    //Get the value stored in the cache, which can be nullptr if the
    //object has already been deleted.
    if(found)
    {
        out_face = it->second.lock();  
    }
    if(out_face == nullptr)
    {
        auto font_data = get_font_data_from_name(name);
        //Don't make_shared so that the control block and object are allocated
        //separately.
        out_face = std::shared_ptr<const FontFace>(
            new FontFace(m_library, font_data, width, height, face_index,
                flags));

        if(found)
        {
            it->second = std::weak_ptr<const FontFace>(out_face);
        }
        else
        {
            m_font_faces.emplace(params, std::weak_ptr<const FontFace>(out_face));
        }
    }
    return out_face;
}

FontFace FontManager::create_font_face(const std::string& name, int width,
        int height, Flags<GlyphLoadFlags> flags, int face_index)
{
    auto font_data = get_font_data_from_name(name);
    return FontFace(m_library, font_data, width, height, face_index,
            flags);
}
 
 
FontManager::FontFileData FontManager::load_font_file(const boost::filesystem::path& font_file)
{
    auto file_size = boost::filesystem::file_size(font_file);
    boost::filesystem::ifstream file_stream(font_file, std::ios::binary | std::ios::in);
    if(!file_stream.is_open())
    {
        //TODO: Throw exception
    }
    FontFileData data(file_size);
    file_stream.read(reinterpret_cast<char*>(data.data()), file_size);
    return data;
}

std::shared_ptr<FontManager::FontFileData> FontManager::get_font_data(
    const boost::filesystem::path& file_name)
{ 
    std::shared_ptr<FontFileData> out_ptr;

    auto it = m_font_data.find(file_name.c_str());
    bool found = (it != m_font_data.end());

    if(found)
    {
        out_ptr = it->second.lock();
    }
    if(out_ptr == nullptr)
    {
        //Don't make_shared so that the control block and object are allocated
        //separately.
        auto font_data = load_font_file(file_name);
        out_ptr = std::shared_ptr<FontFileData>(
            new FontFileData(std::move(font_data)));
        //The weak_ptr data was deleted, we need to refresh it
        if(found)
        {
            it->second = std::weak_ptr<FontFileData>(out_ptr);
        }
        else
        {
            m_font_data.emplace(file_name.c_str(), std::weak_ptr<FontFileData>(out_ptr));
        }
    }
    return out_ptr;
}
 
std::shared_ptr<FontManager::FontFileData> FontManager::get_font_data_from_name(const std::string& font_name)
{
    auto path = get_path_for_font(font_name);
    if(!path)
    {
        //TODO: Throw exception
    }
    return get_font_data(*path);
}
 
boost::optional<boost::filesystem::path> FontManager::get_path_for_font(const std::string& font_name) const
{
    static constexpr std::array<const char*, 2> extensions = {".ttf", ".otf"}; 

    auto file_path_base = m_root_directory;
    file_path_base /= font_name;

    for(auto ext : extensions)
    {
        auto try_path = file_path_base;
        try_path += ext;
        if(boost::filesystem::exists(try_path))
        {
            return boost::optional<boost::filesystem::path>(try_path);
        }
    }
    return boost::optional<boost::filesystem::path>();
}
 
void swap(FontManager& lhs, FontManager& rhs)
{
    using std::swap;
    swap(lhs.m_font_data, rhs.m_font_data);
    swap(lhs.m_font_faces, rhs.m_font_faces);
    swap(lhs.m_library, rhs.m_library);
    swap(lhs.m_root_directory, rhs.m_root_directory);
}

}


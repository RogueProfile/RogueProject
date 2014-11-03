#ifndef FT_FONTMANAGER_H__
#define FT_FONTMANAGER_H__

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/optional.hpp>

#include "Flags.h"

#include "FreeTypeLibrary.h"
#include "Enums.h"

namespace ft
{
class FontFace;

class FontManager
{
    struct FontFaceParams 
    {
        FontFaceParams(std::string name_val, int width_val, int height_val,
                int face_index_val, Flags<GlyphLoadFlags> flags_val):
            name(std::move(name)), width(width_val), height(height_val),
            face_index(face_index_val), flags(flags_val)
        {}
        bool operator ==(const FontFaceParams& rhs) const
        {
            return (name == rhs.name && width == rhs.width &&
                    height == rhs.height && face_index == rhs.face_index &&
                    flags == rhs.flags);
        }
        bool operator !=(const FontFaceParams& rhs) const
        {
            return !(*this == rhs);
        }

        std::string name;
        int width;
        int height;
        int face_index;
        Flags<GlyphLoadFlags> flags;

    };

    struct FontFaceParamsHasher
    {
        size_t operator ()(const FontFaceParams& params) const
        {
            auto hash = std::hash<std::string>()(params.name);
            hash ^= std::hash<int>()(params.width);
            hash ^= std::hash<int>()(params.height);
            hash ^= std::hash<int>()(params.face_index);
            hash ^= params.flags.get_raw_value();
            return hash;
        }
    };

public:
    using FontFileData = std::vector<unsigned char>;
    using FontMap = std::unordered_map<FontFaceParams, 
         std::weak_ptr<const FontFace>, FontFaceParamsHasher>;

    FontManager(boost::filesystem::path root_directory);
    ~FontManager() = default;

    FontManager(const FontManager& other) = delete;
    FontManager(FontManager&& other) noexcept;
    FontManager& operator =(const FontManager& other) = delete;
    FontManager& operator =(FontManager&& other) noexcept;

    FreeTypeLibrary& ft_library() {return m_library;}
    const FreeTypeLibrary& ft_library() const {return m_library;}

    FontFace create_font_face(const std::string& name, int width,
            int height, Flags<GlyphLoadFlags> flags, int face_index);

    std::shared_ptr<const FontFace> get_font_face(const std::string& name,
            int width, int height, Flags<GlyphLoadFlags> flags, int face_index);

    friend void swap(FontManager& lhs, FontManager& rhs);

protected:
    FontFileData load_font_file(const boost::filesystem::path& file_name);
    std::shared_ptr<FontFileData> get_font_data(const boost::filesystem::path& file_name);
    std::shared_ptr<FontFileData> get_font_data_from_name(const std::string& font_name);

    boost::optional<boost::filesystem::path> get_path_for_font(const std::string& font_name) const;

    mutable std::unordered_map<std::string, std::weak_ptr<FontFileData>> m_font_data;
    FontMap m_font_faces;

    FreeTypeLibrary m_library;
    boost::filesystem::path m_root_directory;
};

}

#endif
    

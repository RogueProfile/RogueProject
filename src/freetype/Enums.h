#ifndef FT_ENUMS_H__
#define FT_ENUMS_H__

namespace ft
{
    
    enum class FaceStyleFlags 
    {
        Italic = FT_STYLE_FLAG_ITALIC, Bold = FT_STYLE_FLAG_BOLD
    };

	enum class FaceFlags
	{
		Scalable = FT_FACE_FLAG_SCALABLE,
		FixedSizes = FT_FACE_FLAG_FIXED_SIZES,
		FixedWidth = FT_FACE_FLAG_FIXED_WIDTH,
		SfntFormat = FT_FACE_FLAG_SFNT,
		Horizontal = FT_FACE_FLAG_HORIZONTAL,
		Vertical = FT_FACE_FLAG_VERTICAL,
		Kerning = FT_FACE_FLAG_KERNING,
		MultipleMasters = FT_FACE_FLAG_MULTIPLE_MASTERS,
		GlyphNames = FT_FACE_FLAG_GLYPH_NAMES,
		Hinter = FT_FACE_FLAG_HINTER,
		CidKeyed = FT_FACE_FLAG_CID_KEYED,
		Tricky = FT_FACE_FLAG_TRICKY,
		Color = FT_FACE_FLAG_COLOR
	};

	enum class CharMapEncoding
	{
		Unicode = FT_ENCODING_UNICODE,
		MsSymbol = FT_ENCODING_MS_SYMBOL,
		Sjis = FT_ENCODING_SJIS,
		Gb2312 = FT_ENCODING_GB2312,
		Big5 = FT_ENCODING_BIG5,
		Wansung = FT_ENCODING_WANSUNG,
		Johab = FT_ENCODING_JOHAB,
		Latin1 = FT_ENCODING_ADOBE_LATIN_1,
		AdobeStandard = FT_ENCODING_ADOBE_STANDARD,
		AdobeExpert = FT_ENCODING_ADOBE_EXPERT,
		AdobeCustom = FT_ENCODING_ADOBE_CUSTOM,
		AppleRoman = FT_ENCODING_APPLE_ROMAN
	};

	enum class GlyphLoadFlags
	{
		NoScale = FT_LOAD_NO_SCALE,
		NoHinting = FT_LOAD_NO_HINTING,
		NoBitmap = FT_LOAD_NO_BITMAP,
		Render = FT_LOAD_RENDER,
		VerticalLayout = FT_LOAD_VERTICAL_LAYOUT,
		ForceAutohint = FT_LOAD_FORCE_AUTOHINT,
		CropBitmap = FT_LOAD_CROP_BITMAP,
		Pedantic = FT_LOAD_PEDANTIC,
		Monochrome = FT_LOAD_MONOCHROME,
		LinearDesign = FT_LOAD_LINEAR_DESIGN,
		NoAutohint = FT_LOAD_NO_AUTOHINT,
		LoadColor = FT_LOAD_COLOR
	};

	enum class KerningMode
	{
		Default = FT_KERNING_DEFAULT,
		Unfitted = FT_KERNING_UNFITTED,
		Unscaled = FT_KERNING_UNSCALED
	};

    enum class GlyphFormat
	{
		Composite = FT_GLYPH_FORMAT_COMPOSITE,
		Bitmap = FT_GLYPH_FORMAT_BITMAP,
		Outline = FT_GLYPH_FORMAT_OUTLINE,
		Plotter = FT_GLYPH_FORMAT_PLOTTER
	};

    enum class PixelMode
	{
		Mono = FT_PIXEL_MODE_MONO,
		Gray = FT_PIXEL_MODE_GRAY,
		Gray2 = FT_PIXEL_MODE_GRAY2,
		Gray4 = FT_PIXEL_MODE_GRAY4,
		Lcd = FT_PIXEL_MODE_LCD,
		LcdV = FT_PIXEL_MODE_LCD_V,
		Bgra = FT_PIXEL_MODE_BGRA
	};   

    enum class GlyphRenderMode
	{
		Normal = FT_RENDER_MODE_NORMAL,
		Mono = FT_RENDER_MODE_MONO,
		Lcd = FT_RENDER_MODE_LCD,
		LcdV = FT_RENDER_MODE_LCD_V
	};
}

#endif

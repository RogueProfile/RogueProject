#ifndef GL_TEXTURE_H__
#define GL_TEXTURE_H__

#include "GlObject.h"

namespace gl
{

class Texture: public GlObject
{
public:
    enum class ClampMode {Border = GL_CLAMP_TO_BORDER, Edge = GL_CLAMP_TO_EDGE, Repeat = GL_REPEAT,
			MirroredRepeat = GL_MIRRORED_REPEAT};

	enum class FilterMode {Nearest = GL_NEAREST, Linear = GL_LINEAR, MipmapNearest = GL_NEAREST_MIPMAP_NEAREST,
			MipmapLinear = GL_LINEAR_MIPMAP_NEAREST, LinearMipmapNearest = GL_NEAREST_MIPMAP_LINEAR,
			MipmapBilinear = GL_LINEAR_MIPMAP_LINEAR};

	enum class DataPixelFormat {RGBA = GL_RGBA, RGB = GL_RGB, BGRA = GL_BGRA, BGR = GL_BGR,
			Red = GL_RED, Green = GL_GREEN, Blue = GL_BLUE};

	enum class PixelType {UByte = GL_UNSIGNED_BYTE, Byte = GL_BYTE,
		UShort = GL_UNSIGNED_SHORT, Short = GL_SHORT,
		UInt = GL_UNSIGNED_INT, Int = GL_INT,
		Float = GL_FLOAT,
		UByte332 = GL_UNSIGNED_BYTE_3_3_2,
		UByte332Reverse = GL_UNSIGNED_BYTE_2_3_3_REV,
		UShort565 = GL_UNSIGNED_SHORT_5_6_5,
		UShort565Reverse = GL_UNSIGNED_SHORT_5_6_5_REV,
		UShort4444 = GL_UNSIGNED_SHORT_4_4_4_4,
		UShort4444Reverse = GL_UNSIGNED_SHORT_4_4_4_4_REV,
		UShort5551 = GL_UNSIGNED_SHORT_5_5_5_1,
		UShort1555Reverse = GL_UNSIGNED_SHORT_1_5_5_5_REV,
		UInt8888 = GL_UNSIGNED_INT_8_8_8_8,
		UInt8888Reverse = GL_UNSIGNED_INT_8_8_8_8_REV,
		UInt1010102 = GL_UNSIGNED_INT_10_10_10_2,
		UInt2101010Reverse = GL_UNSIGNED_INT_2_10_10_10_REV};

	///Internal pixel formats for OpenGL textures.
	///@see http://www.opengl.org/wiki/GLAPI/glTexImage2D
	enum class InternalPixelFormat{RGBA = GL_RGBA, RGB = GL_RGB, RG = GL_RG, Red = GL_RED,
		R8 = GL_R8,
		R8SNorm = GL_R8_SNORM,
		R16 = GL_R16,
		R16SNorm = GL_R16_SNORM,
		RG8 = GL_RG8,
		RG8SNorm = GL_RG8_SNORM,
		RG16 = GL_RG16,
		RG16SNorm = GL_RG16_SNORM,
		R3_G3_B2 = GL_R3_G3_B2,
		RGB4 = GL_RGB4,
		RGB5 = GL_RGB5,
		RGB8 = GL_RGB8,
		RGB8SNorm = GL_RGB8_SNORM,
		RGB10 = GL_RGB10,
		RGB12 = GL_RGB12,
		RGB16SNorm = GL_RGB16_SNORM,
		RGBA2 = GL_RGBA2,
		RGBA4 = GL_RGBA4,
		RGB5_A1 = GL_RGB5_A1,
		RGBA8 = GL_RGBA8,
		RGBA8SNorm = GL_RGBA8_SNORM,
		RGB10A2 = GL_RGB10_A2,
		RGB10A2UI = GL_RGB10_A2UI,
		RGBA12 = GL_RGBA12,
		RGBA16 = GL_RGBA16,
		SRGB8 = GL_SRGB8,
		SRGB8Alpha8 = GL_SRGB8_ALPHA8,
		R16F = GL_R16F,
		RG16F = GL_RG16F,
		RGB16F = GL_RGB16F,
		RGBA16F = GL_RGBA16F,
		R32F = GL_R32F,
		RG32F = GL_RG32F,
		RGB32F = GL_RGB32F,
		RGBA32F = GL_RGBA32F,
		R11FG11FB10F = GL_R11F_G11F_B10F,
		RGB9_E5 = GL_RGB9_E5,
		R8I = GL_R8I,
		R8UI = GL_R8UI,
		R16I = GL_R16I,
		R16UI = GL_R16UI,
		R32I = GL_R32I,
		R32UI = GL_R32UI,
		RG8I = GL_RG8I,
		RG8UI = GL_RG8UI,
		RG16I = GL_RG16I,
		RG16UI = GL_RG16UI,
		RG32I = GL_RG32I,
		RG32UI = GL_RG32UI,
		RGB8I = GL_RGB8I,
		RGB8UI = GL_RGB8UI,
		RGB16I = GL_RGB16I,
		RGB16UI = GL_RGB16UI,
		RGB32I = GL_RGB32I,
		RGB32UI = GL_RGB32UI,
		RGBA8I = GL_RGBA8I,
		RGBA8UI = GL_RGBA8UI,
		RGBA16I = GL_RGBA16I,
		RGBA16UI = GL_RGBA16UI,
		RGBA32I = GL_RGBA32I,
		RGBA32UI = GL_RGBA32UI,
		CompressedRed = GL_COMPRESSED_RED,
		CompressedRG = GL_COMPRESSED_RG,
		CompressedRGB = GL_COMPRESSED_RGB,
		CompressedRGBA = GL_COMPRESSED_RGBA,
		CompressedSRGB = GL_COMPRESSED_SRGB,
		CompressedSRGBAlpha = GL_COMPRESSED_SRGB_ALPHA,
		CompressedRedRGTC1 = GL_COMPRESSED_RED_RGTC1,
		CompressedSignedRedRGTC1 = GL_COMPRESSED_SIGNED_RED_RGTC1,
		CompressedRGRGTC2 = GL_COMPRESSED_RG_RGTC2,
		CompressedSignedRGBABPTCUNorm = GL_COMPRESSED_RGBA_BPTC_UNORM,
		CompressedSRGBAlphaBPTCUNorm = GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
		CompressedRGBBPTCSignedFloat = GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
		CompressedRGBBPTCUnsignedFloat = GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
		CompressedRGBS3TCDXT1 = GL_COMPRESSED_RGB_S3TC_DXT1_EXT,
		CompressedSRGBS3TCDXT1 = GL_COMPRESSED_SRGB_S3TC_DXT1_EXT,
		CompressedRGBAS3TCDXT1 = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT,
		CompressedSRGBAlphaS3TCDXT1 = GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT,
		CompressedRGBAS3TCDXT3 = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT,
		CompressedSRGBAlphaS3TCDXT3 = GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT,
		CompressedRGBAS3TCDXT5 = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT,
		CompressedSGBAlphaS3TCDXT5 = GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT};

    Texture() = default;
    virtual ~Texture() = default;

    Texture(const Texture& other) = delete;
    Texture(Texture&& other) noexcept = default;
    Texture& operator =(const Texture& other) = delete;
    Texture& operator =(Texture&& other) noexcept = default;

    static int pixel_size_for_format(DataPixelFormat pixel_format,
            PixelType pixel_type);

protected:
private:
};

}

#endif
    

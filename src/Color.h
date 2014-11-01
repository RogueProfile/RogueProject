#ifndef COLOR_H__
#define COLOR_H__

#include <cstdint>

class HsvColor;

class Color
{
public:
    constexpr Color():
        red(0.0f), green(0.0f), blue(0.0f), alpha(1.0f)
    {}
    constexpr Color(float red_value, float green_value, float blue_value, float alpha_value):
        red(red_value), green(green_value), blue(blue_value), alpha(alpha_value)
    {}
    constexpr Color(float red_value, float green_value, float blue_value):
        Color(red_value, green_value, blue_value, 1)
    {}
    constexpr Color(uint8_t red_value, uint8_t green_value, uint8_t blue_value, uint8_t alpha_value):
        Color(red_value/255.f, green_value/255.f, blue_value/255.f, alpha_value/255.f)
    {}
    constexpr Color(uint8_t red_value, uint8_t green_value, uint8_t blue_value):
        Color(red_value/255.f, green_value/255.f, blue_value/255.f, 1)
    {}
    constexpr Color(uint32_t rgba):
        Color(((rgba >> 24)/255.f), (((rgba >> 16) & 0xFF)/255.f),
            (((rgba >> 8) & 0xFF)/255.f), ((rgba & 0xFF)/255.f))
    {}

    ~Color() = default;
    
    constexpr Color(const Color&) = default;
    constexpr Color(Color&&) = default;
    constexpr Color& operator =(const Color&) = default;
    constexpr Color& operator =(Color&&) noexcept = default;

    constexpr bool operator==(const Color& color) const;
    constexpr bool operator!=(const Color& color) const;
    constexpr uint32_t to_rgba() const;
    constexpr uint32_t to_abgr() const;

    HsvColor to_hsv() const;


    static constexpr Color dark_red() {return Color(0.5450980392156862f, 0.0f, 0.0f, 1.0f);}
    static constexpr Color light_grey() {return Color(0.8274509803921568f, 0.8274509803921568f, 0.8274509803921568f, 1.0f);}
    static constexpr Color chocolate() {return Color(0.8235294117647058f, 0.4117647058823529f, 0.11764705882352941f, 1.0f);}
    static constexpr Color dark_slate_gray() {return Color(0.1843137254901961f, 0.30980392156862746f, 0.30980392156862746f, 1.0f);}
    static constexpr Color olive() {return Color(0.5019607843137255f, 0.5019607843137255f, 0.0f, 1.0f);}
    static constexpr Color floral_white() {return Color(1.0f, 0.9803921568627451f, 0.9411764705882353f, 1.0f);}
    static constexpr Color teal() {return Color(0.0f, 0.5019607843137255f, 0.5019607843137255f, 1.0f);}
    static constexpr Color turquoise() {return Color(0.25098039215686274f, 0.8784313725490196f, 0.8156862745098039f, 1.0f);}
    static constexpr Color dark_goldenrod() {return Color(0.7215686274509804f, 0.5254901960784314f, 0.043137254901960784f, 1.0f);}
    static constexpr Color lime_green() {return Color(0.19607843137254902f, 0.803921568627451f, 0.19607843137254902f, 1.0f);}
    static constexpr Color slate_blue() {return Color(0.41568627450980394f, 0.35294117647058826f, 0.803921568627451f, 1.0f);}
    static constexpr Color blanched_almond() {return Color(1.0f, 0.9215686274509803f, 0.803921568627451f, 1.0f);}
    static constexpr Color dark_slate_blue() {return Color(0.2823529411764706f, 0.23921568627450981f, 0.5450980392156862f, 1.0f);}
    static constexpr Color pure_green() {return Color(0.0f, 0.5019607843137255f, 0.0f, 1.0f);}
    static constexpr Color magenta() {return Color(1.0f, 0.0f, 1.0f, 1.0f);}
    static constexpr Color orange() {return Color(1.0f, 0.6470588235294118f, 0.0f, 1.0f);}
    static constexpr Color white_smoke() {return Color(0.9607843137254902f, 0.9607843137254902f, 0.9607843137254902f, 1.0f);}
    static constexpr Color green_yellow() {return Color(0.6784313725490196f, 1.0f, 0.1843137254901961f, 1.0f);}
    static constexpr Color gainsboro() {return Color(0.8627450980392157f, 0.8627450980392157f, 0.8627450980392157f, 1.0f);}
    static constexpr Color violet() {return Color(0.9333333333333333f, 0.5098039215686274f, 0.9333333333333333f, 1.0f);}
    static constexpr Color black() {return Color(0.0f, 0.0f, 0.0f, 1.0f);}
    static constexpr Color lavender_blush() {return Color(1.0f, 0.9411764705882353f, 0.9607843137254902f, 1.0f);}
    static constexpr Color medium_blue() {return Color(0.0f, 0.0f, 0.803921568627451f, 1.0f);}
    static constexpr Color linen() {return Color(0.9803921568627451f, 0.9411764705882353f, 0.9019607843137255f, 1.0f);}
    static constexpr Color medium_sea_green() {return Color(0.23529411764705882f, 0.7019607843137254f, 0.44313725490196076f, 1.0f);}
    static constexpr Color dark_salmon() {return Color(0.9137254901960784f, 0.5882352941176471f, 0.47843137254901963f, 1.0f);}
    static constexpr Color goldenrod() {return Color(0.8549019607843137f, 0.6470588235294118f, 0.12549019607843137f, 1.0f);}
    static constexpr Color powder_blue() {return Color(0.6901960784313725f, 0.8784313725490196f, 0.9019607843137255f, 1.0f);}
    static constexpr Color maroon() {return Color(0.5019607843137255f, 0.0f, 0.0f, 1.0f);}
    static constexpr Color dark_orange() {return Color(1.0f, 0.5490196078431373f, 0.0f, 1.0f);}
    static constexpr Color alice_blue() {return Color(0.9411764705882353f, 0.9725490196078431f, 1.0f, 1.0f);}
    static constexpr Color dark_turquoise() {return Color(0.0f, 0.807843137254902f, 0.8196078431372549f, 1.0f);}
    static constexpr Color rosy_brown() {return Color(0.7372549019607844f, 0.5607843137254902f, 0.5607843137254902f, 1.0f);}
    static constexpr Color pale_violet_red() {return Color(0.8588235294117647f, 0.4392156862745098f, 0.5764705882352941f, 1.0f);}
    static constexpr Color dark_magenta() {return Color(0.5450980392156862f, 0.0f, 0.5450980392156862f, 1.0f);}
    static constexpr Color tomato() {return Color(1.0f, 0.38823529411764707f, 0.2784313725490196f, 1.0f);}
    static constexpr Color gray() {return Color(0.5019607843137255f, 0.5019607843137255f, 0.5019607843137255f, 1.0f);}
    static constexpr Color deep_pink() {return Color(1.0f, 0.0784313725490196f, 0.5764705882352941f, 1.0f);}
    static constexpr Color midnight_blue() {return Color(0.09803921568627451f, 0.09803921568627451f, 0.4392156862745098f, 1.0f);}
    static constexpr Color light_cyan() {return Color(0.8784313725490196f, 1.0f, 1.0f, 1.0f);}
    static constexpr Color chartreuse() {return Color(0.4980392156862745f, 1.0f, 0.0f, 1.0f);}
    static constexpr Color dark_orchid() {return Color(0.6f, 0.19607843137254902f, 0.8f, 1.0f);}
    static constexpr Color olive_drab() {return Color(0.4196078431372549f, 0.5568627450980392f, 0.13725490196078433f, 1.0f);}
    static constexpr Color pink() {return Color(1.0f, 0.7529411764705882f, 0.796078431372549f, 1.0f);}
    static constexpr Color navy() {return Color(0.0f, 0.0f, 0.5019607843137255f, 1.0f);}
    static constexpr Color pale_turquoise() {return Color(0.6862745098039216f, 0.9333333333333333f, 0.9333333333333333f, 1.0f);}
    static constexpr Color azure() {return Color(0.9411764705882353f, 1.0f, 1.0f, 1.0f);}
    static constexpr Color light_coral() {return Color(0.9411764705882353f, 0.5019607843137255f, 0.5019607843137255f, 1.0f);}
    static constexpr Color lavender() {return Color(0.9019607843137255f, 0.9019607843137255f, 0.9803921568627451f, 1.0f);}
    static constexpr Color steel_blue() {return Color(0.27450980392156865f, 0.5098039215686274f, 0.7058823529411765f, 1.0f);}
    static constexpr Color beige() {return Color(0.9607843137254902f, 0.9607843137254902f, 0.8627450980392157f, 1.0f);}
    static constexpr Color orange_red() {return Color(1.0f, 0.27058823529411763f, 0.0f, 1.0f);}
    static constexpr Color light_goldenrod_yellow() {return Color(0.9803921568627451f, 0.9803921568627451f, 0.8235294117647058f, 1.0f);}
    static constexpr Color ghost_white() {return Color(0.9725490196078431f, 0.9725490196078431f, 1.0f, 1.0f);}
    static constexpr Color gold() {return Color(1.0f, 0.8431372549019608f, 0.0f, 1.0f);}
    static constexpr Color dark_green() {return Color(0.0f, 0.39215686274509803f, 0.0f, 1.0f);}
    static constexpr Color bisque() {return Color(1.0f, 0.8941176470588236f, 0.7686274509803922f, 1.0f);}
    static constexpr Color pure_red() {return Color(1.0f, 0.0f, 0.0f, 1.0f);}
    static constexpr Color indigo() {return Color(0.29411764705882354f, 0.0f, 0.5098039215686274f, 1.0f);}
    static constexpr Color white() {return Color(1.0f, 1.0f, 1.0f, 1.0f);}
    static constexpr Color medium_slate_blue() {return Color(0.4823529411764706f, 0.40784313725490196f, 0.9333333333333333f, 1.0f);}
    static constexpr Color sea_green() {return Color(0.1803921568627451f, 0.5450980392156862f, 0.3411764705882353f, 1.0f);}
    static constexpr Color forest_green() {return Color(0.13333333333333333f, 0.5450980392156862f, 0.13333333333333333f, 1.0f);}
    static constexpr Color cornflower_blue() {return Color(0.39215686274509803f, 0.5843137254901961f, 0.9294117647058824f, 1.0f);}
    static constexpr Color sky_blue() {return Color(0.5294117647058824f, 0.807843137254902f, 0.9215686274509803f, 1.0f);}
    static constexpr Color spring_green() {return Color(0.0f, 1.0f, 0.4980392156862745f, 1.0f);}
    static constexpr Color crimson() {return Color(0.8627450980392157f, 0.0784313725490196f, 0.23529411764705882f, 1.0f);}
    static constexpr Color silver() {return Color(0.7529411764705882f, 0.7529411764705882f, 0.7529411764705882f, 1.0f);}
    static constexpr Color blue_violet() {return Color(0.5411764705882353f, 0.16862745098039217f, 0.8862745098039215f, 1.0f);}
    static constexpr Color dark_violet() {return Color(0.5803921568627451f, 0.0f, 0.8274509803921568f, 1.0f);}
    static constexpr Color cyan() {return Color(0.0f, 1.0f, 1.0f, 1.0f);}
    static constexpr Color dim_gray() {return Color(0.4117647058823529f, 0.4117647058823529f, 0.4117647058823529f, 1.0f);}
    static constexpr Color antique_white() {return Color(0.9803921568627451f, 0.9215686274509803f, 0.8431372549019608f, 1.0f);}
    static constexpr Color pure_blue() {return Color(0.0f, 0.0f, 1.0f, 1.0f);}
    static constexpr Color plum() {return Color(0.8666666666666667f, 0.6274509803921569f, 0.8666666666666667f, 1.0f);}
    static constexpr Color navajo_white() {return Color(1.0f, 0.8705882352941177f, 0.6784313725490196f, 1.0f);}
    static constexpr Color cadet_blue() {return Color(0.37254901960784315f, 0.6196078431372549f, 0.6274509803921569f, 1.0f);}
    static constexpr Color dark_olive_green() {return Color(0.3333333333333333f, 0.4196078431372549f, 0.1843137254901961f, 1.0f);}
    static constexpr Color light_yellow() {return Color(1.0f, 1.0f, 0.8784313725490196f, 1.0f);}
    static constexpr Color brown() {return Color(0.6470588235294118f, 0.16470588235294117f, 0.16470588235294117f, 1.0f);}
    static constexpr Color lemon_chiffon() {return Color(1.0f, 0.9803921568627451f, 0.803921568627451f, 1.0f);}
    static constexpr Color aquamarine() {return Color(0.4980392156862745f, 1.0f, 0.8313725490196079f, 1.0f);}
    static constexpr Color fire_brick() {return Color(0.6980392156862745f, 0.13333333333333333f, 0.13333333333333333f, 1.0f);}
    static constexpr Color medium_aquamarine() {return Color(0.4f, 0.803921568627451f, 0.6666666666666666f, 1.0f);}
    static constexpr Color misty_rose() {return Color(1.0f, 0.8941176470588236f, 0.8823529411764706f, 1.0f);}
    static constexpr Color ivory() {return Color(1.0f, 1.0f, 0.9411764705882353f, 1.0f);}
    static constexpr Color papaya_whip() {return Color(1.0f, 0.9372549019607843f, 0.8352941176470589f, 1.0f);}
    static constexpr Color pale_green() {return Color(0.596078431372549f, 0.984313725490196f, 0.596078431372549f, 1.0f);}
    static constexpr Color hot_pink() {return Color(1.0f, 0.4117647058823529f, 0.7058823529411765f, 1.0f);}
    static constexpr Color medium_purple() {return Color(0.5764705882352941f, 0.4392156862745098f, 0.8588235294117647f, 1.0f);}
    static constexpr Color dark_gray() {return Color(0.6627450980392157f, 0.6627450980392157f, 0.6627450980392157f, 1.0f);}
    static constexpr Color moccasin() {return Color(1.0f, 0.8941176470588236f, 0.7098039215686275f, 1.0f);}
    static constexpr Color saddle_brown() {return Color(0.5450980392156862f, 0.27058823529411763f, 0.07450980392156863f, 1.0f);}
    static constexpr Color sienna() {return Color(0.6274509803921569f, 0.3215686274509804f, 0.17647058823529413f, 1.0f);}
    static constexpr Color mint_cream() {return Color(0.9607843137254902f, 1.0f, 0.9803921568627451f, 1.0f);}
    static constexpr Color light_green() {return Color(0.5647058823529412f, 0.9333333333333333f, 0.5647058823529412f, 1.0f);}
    static constexpr Color tan() {return Color(0.8235294117647058f, 0.7058823529411765f, 0.5490196078431373f, 1.0f);}
    static constexpr Color light_sky_blue() {return Color(0.5294117647058824f, 0.807843137254902f, 0.9803921568627451f, 1.0f);}
    static constexpr Color light_pink() {return Color(1.0f, 0.7137254901960784f, 0.7568627450980392f, 1.0f);}
    static constexpr Color medium_turquoise() {return Color(0.2823529411764706f, 0.8196078431372549f, 0.8f, 1.0f);}
    static constexpr Color lime() {return Color(0.0f, 1.0f, 0.0f, 1.0f);}
    static constexpr Color coral() {return Color(1.0f, 0.4980392156862745f, 0.3137254901960784f, 1.0f);}
    static constexpr Color cornsilk() {return Color(1.0f, 0.9725490196078431f, 0.8627450980392157f, 1.0f);}
    static constexpr Color aqua() {return Color(0.0f, 1.0f, 1.0f, 1.0f);}
    static constexpr Color honeydew() {return Color(0.9411764705882353f, 1.0f, 0.9411764705882353f, 1.0f);}
    static constexpr Color deep_sky_blue() {return Color(0.0f, 0.7490196078431373f, 1.0f, 1.0f);}
    static constexpr Color indian_red() {return Color(0.803921568627451f, 0.3607843137254902f, 0.3607843137254902f, 1.0f);}
    static constexpr Color purple() {return Color(0.5019607843137255f, 0.0f, 0.5019607843137255f, 1.0f);}
    static constexpr Color khaki() {return Color(0.9411764705882353f, 0.9019607843137255f, 0.5490196078431373f, 1.0f);}
    static constexpr Color wheat() {return Color(0.9607843137254902f, 0.8705882352941177f, 0.7019607843137254f, 1.0f);}
    static constexpr Color sandy_brown() {return Color(0.9568627450980393f, 0.6431372549019608f, 0.3764705882352941f, 1.0f);}
    static constexpr Color lawn_green() {return Color(0.48627450980392156f, 0.9882352941176471f, 0.0f, 1.0f);}
    static constexpr Color light_steel_blue() {return Color(0.6901960784313725f, 0.7686274509803922f, 0.8705882352941177f, 1.0f);}
    static constexpr Color yellow() {return Color(1.0f, 1.0f, 0.0f, 1.0f);}
    static constexpr Color peach_puff() {return Color(1.0f, 0.8549019607843137f, 0.7254901960784313f, 1.0f);}
    static constexpr Color medium_orchid() {return Color(0.7294117647058823f, 0.3333333333333333f, 0.8274509803921568f, 1.0f);}
    static constexpr Color fuchsia() {return Color(1.0f, 0.0f, 1.0f, 1.0f);}
    static constexpr Color dodger_blue() {return Color(0.11764705882352941f, 0.5647058823529412f, 1.0f, 1.0f);}
    static constexpr Color yellow_green() {return Color(0.6039215686274509f, 0.803921568627451f, 0.19607843137254902f, 1.0f);}
    static constexpr Color light_blue() {return Color(0.6784313725490196f, 0.8470588235294118f, 0.9019607843137255f, 1.0f);}
    static constexpr Color light_sea_green() {return Color(0.12549019607843137f, 0.6980392156862745f, 0.6666666666666666f, 1.0f);}
    static constexpr Color seashell() {return Color(1.0f, 0.9607843137254902f, 0.9333333333333333f, 1.0f);}
    static constexpr Color snow() {return Color(1.0f, 0.9803921568627451f, 0.9803921568627451f, 1.0f);}
    static constexpr Color royal_blue() {return Color(0.2549019607843137f, 0.4117647058823529f, 0.8823529411764706f, 1.0f);}
    static constexpr Color slate_gray() {return Color(0.4392156862745098f, 0.5019607843137255f, 0.5647058823529412f, 1.0f);}
    static constexpr Color pale_goldenrod() {return Color(0.9333333333333333f, 0.9098039215686274f, 0.6666666666666666f, 1.0f);}
    static constexpr Color peru() {return Color(0.803921568627451f, 0.5215686274509804f, 0.24705882352941178f, 1.0f);}
    static constexpr Color medium_violet_red() {return Color(0.7803921568627451f, 0.08235294117647059f, 0.5215686274509804f, 1.0f);}
    static constexpr Color medium_spring_green() {return Color(0.0f, 0.9803921568627451f, 0.6039215686274509f, 1.0f);}
    static constexpr Color dark_khaki() {return Color(0.7411764705882353f, 0.7176470588235294f, 0.4196078431372549f, 1.0f);}
    static constexpr Color salmon() {return Color(0.9803921568627451f, 0.5019607843137255f, 0.4470588235294118f, 1.0f);}
    static constexpr Color dark_cyan() {return Color(0.0f, 0.5450980392156862f, 0.5450980392156862f, 1.0f);}
    static constexpr Color dark_blue() {return Color(0.0f, 0.0f, 0.5450980392156862f, 1.0f);}
    static constexpr Color dark_sea_green() {return Color(0.5607843137254902f, 0.7372549019607844f, 0.5607843137254902f, 1.0f);}
    static constexpr Color thistle() {return Color(0.8470588235294118f, 0.7490196078431373f, 0.8470588235294118f, 1.0f);}
    static constexpr Color light_slate_gray() {return Color(0.4666666666666667f, 0.5333333333333333f, 0.6f, 1.0f);}
    static constexpr Color old_lace() {return Color(0.9921568627450981f, 0.9607843137254902f, 0.9019607843137255f, 1.0f);}
    static constexpr Color orchid() {return Color(0.8549019607843137f, 0.4392156862745098f, 0.8392156862745098f, 1.0f);}
    static constexpr Color burly_wood() {return Color(0.8705882352941177f, 0.7215686274509804f, 0.5294117647058824f, 1.0f);}
    static constexpr Color light_salmon() {return Color(1.0f, 0.6274509803921569f, 0.47843137254901963f, 1.0f);}

    
    float red;
    float green;
    float blue;
    float alpha;
};
inline constexpr bool Color::operator==(const Color& color) const
{
    return (red == color.red && green == color.green && blue == color.blue && alpha == color.alpha);
}

inline constexpr bool Color::operator!=(const Color& color) const
{
    return !(*this == color);
}
 
inline constexpr uint32_t Color::to_rgba() const
{
    return (static_cast<uint32_t>(red*255) << 24
            | static_cast<uint32_t>(green*255) << 16
            | static_cast<uint32_t>(blue*255) << 8
            | static_cast<uint32_t>(alpha*255));
}
 
inline constexpr uint32_t Color::to_abgr() const
{
    return (static_cast<uint32_t>(alpha*255) << 24
           | static_cast<uint32_t>(blue*255) << 16
           | static_cast<uint32_t>(green*255) << 8
           | static_cast<uint32_t>(red*255));
} 

 
#endif

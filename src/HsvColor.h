#ifndef HSVCOLOR_H__
#define HSVCOLOR_H__

#include "Angle.h"

class Color;

class HsvColor
{
public:
    constexpr HsvColor(Degrees<float> hue_value, float saturation_value,
           float value_value, float alpha_value=1):
        hue(hue_value), saturation(saturation_value), value(value_value), alpha(alpha_value)
    {}

    ~HsvColor() = default;

    constexpr HsvColor(const HsvColor& other) = default;
    constexpr HsvColor(HsvColor&& other) noexcept = default;
    constexpr HsvColor& operator =(const HsvColor& other) = default;
    constexpr HsvColor& operator =(HsvColor&& other) noexcept = default;

    constexpr Color to_rgb();
    static HsvColor from_rgb(const Color& that); 

    Degrees<float> hue;
    float saturation;
    float value;
    float alpha;

    static constexpr HsvColor dark_red() {return HsvColor(Degrees<float>(0.0f), 1.0f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor light_grey() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor chocolate() {return HsvColor(Degrees<float>(24.999999999999996f), 0.8571428571428571f, 0.8235294117647058f, 1.0f);}
    static constexpr HsvColor dark_slate_gray() {return HsvColor(Degrees<float>(180.0f), 0.4050632911392405f, 0.30980392156862746f, 1.0f);}
    static constexpr HsvColor olive() {return HsvColor(Degrees<float>(60.0f), 1.0f, 0.5019607843137255f, 1.0f);}
    static constexpr HsvColor floral_white() {return HsvColor(Degrees<float>(39.999999999999964f), 0.05882352941176472f, 1.0f, 1.0f);}
    static constexpr HsvColor teal() {return HsvColor(Degrees<float>(180.0f), 1.0f, 0.5019607843137255f, 1.0f);}
    static constexpr HsvColor turquoise() {return HsvColor(Degrees<float>(174.0f), 0.7142857142857143f, 0.8784313725490196f, 1.0f);}
    static constexpr HsvColor dark_goldenrod() {return HsvColor(Degrees<float>(42.65895953757225f), 0.9402173913043479f, 0.7215686274509804f, 1.0f);}
    static constexpr HsvColor lime_green() {return HsvColor(Degrees<float>(120.0f), 0.7560975609756098f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor slate_blue() {return HsvColor(Degrees<float>(248.34782608695653f), 0.5609756097560975f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor blanched_almond() {return HsvColor(Degrees<float>(35.99999999999998f), 0.196078431372549f, 1.0f, 1.0f);}
    static constexpr HsvColor dark_slate_blue() {return HsvColor(Degrees<float>(248.46153846153848f), 0.5611510791366905f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor pure_green() {return HsvColor(Degrees<float>(120.0f), 1.0f, 0.5019607843137255f, 1.0f);}
    static constexpr HsvColor magenta() {return HsvColor(Degrees<float>(300.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor orange() {return HsvColor(Degrees<float>(38.82352941176471f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor white_smoke() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor green_yellow() {return HsvColor(Degrees<float>(83.65384615384615f), 0.8156862745098039f, 1.0f, 1.0f);}
    static constexpr HsvColor gainsboro() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor violet() {return HsvColor(Degrees<float>(300.0f), 0.45378151260504207f, 0.9333333333333333f, 1.0f);}
    static constexpr HsvColor black() {return HsvColor(Degrees<float>(0.0f), 0.0f, 0.0f, 1.0f);}
    static constexpr HsvColor lavender_blush() {return HsvColor(Degrees<float>(339.99999999999994f), 0.05882352941176472f, 1.0f, 1.0f);}
    static constexpr HsvColor medium_blue() {return HsvColor(Degrees<float>(240.0f), 1.0f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor linen() {return HsvColor(Degrees<float>(30.0f), 0.07999999999999995f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor medium_sea_green() {return HsvColor(Degrees<float>(146.72268907563026f), 0.664804469273743f, 0.7019607843137254f, 1.0f);}
    static constexpr HsvColor dark_salmon() {return HsvColor(Degrees<float>(15.135135135135137f), 0.4763948497854077f, 0.9137254901960784f, 1.0f);}
    static constexpr HsvColor goldenrod() {return HsvColor(Degrees<float>(42.903225806451616f), 0.8532110091743119f, 0.8549019607843137f, 1.0f);}
    static constexpr HsvColor powder_blue() {return HsvColor(Degrees<float>(186.66666666666666f), 0.2347826086956522f, 0.9019607843137255f, 1.0f);}
    static constexpr HsvColor maroon() {return HsvColor(Degrees<float>(0.0f), 1.0f, 0.5019607843137255f, 1.0f);}
    static constexpr HsvColor dark_orange() {return HsvColor(Degrees<float>(32.94117647058824f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor alice_blue() {return HsvColor(Degrees<float>(208.0f), 0.05882352941176472f, 1.0f, 1.0f);}
    static constexpr HsvColor dark_turquoise() {return HsvColor(Degrees<float>(180.86124401913875f), 1.0f, 0.8196078431372549f, 1.0f);}
    static constexpr HsvColor rosy_brown() {return HsvColor(Degrees<float>(0.0f), 0.23936170212765961f, 0.7372549019607844f, 1.0f);}
    static constexpr HsvColor pale_violet_red() {return HsvColor(Degrees<float>(340.3738317757009f), 0.4885844748858447f, 0.8588235294117647f, 1.0f);}
    static constexpr HsvColor dark_magenta() {return HsvColor(Degrees<float>(300.0f), 1.0f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor tomato() {return HsvColor(Degrees<float>(9.130434782608695f), 0.7215686274509804f, 1.0f, 1.0f);}
    static constexpr HsvColor gray() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor deep_pink() {return HsvColor(Degrees<float>(327.5744680851064f), 0.9215686274509804f, 1.0f, 1.0f);}
    static constexpr HsvColor midnight_blue() {return HsvColor(Degrees<float>(240.0f), 0.7767857142857143f, 0.4392156862745098f, 1.0f);}
    static constexpr HsvColor light_cyan() {return HsvColor(Degrees<float>(180.0f), 0.1215686274509804f, 1.0f, 1.0f);}
    static constexpr HsvColor chartreuse() {return HsvColor(Degrees<float>(90.11764705882354f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor dark_orchid() {return HsvColor(Degrees<float>(280.12987012987014f), 0.7549019607843138f, 0.8f, 1.0f);}
    static constexpr HsvColor olive_drab() {return HsvColor(Degrees<float>(79.62616822429906f), 0.7535211267605634f, 0.5568627450980392f, 1.0f);}
    static constexpr HsvColor pink() {return HsvColor(Degrees<float>(349.5238095238095f), 0.24705882352941178f, 1.0f, 1.0f);}
    static constexpr HsvColor navy() {return HsvColor(Degrees<float>(240.0f), 1.0f, 0.5019607843137255f, 1.0f);}
    static constexpr HsvColor pale_turquoise() {return HsvColor(Degrees<float>(180.0f), 0.2647058823529412f, 0.9333333333333333f, 1.0f);}
    static constexpr HsvColor azure() {return HsvColor(Degrees<float>(180.0f), 0.05882352941176472f, 1.0f, 1.0f);}
    static constexpr HsvColor light_coral() {return HsvColor(Degrees<float>(0.0f), 0.4666666666666667f, 0.9411764705882353f, 1.0f);}
    static constexpr HsvColor lavender() {return HsvColor(Degrees<float>(240.0f), 0.07999999999999995f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor steel_blue() {return HsvColor(Degrees<float>(207.27272727272728f), 0.611111111111111f, 0.7058823529411765f, 1.0f);}
    static constexpr HsvColor beige() {return HsvColor(Degrees<float>(60.0f), 0.10204081632653059f, 0.9607843137254902f, 1.0f);}
    static constexpr HsvColor orange_red() {return HsvColor(Degrees<float>(16.235294117647058f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor light_goldenrod_yellow() {return HsvColor(Degrees<float>(60.0f), 0.16f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor ghost_white() {return HsvColor(Degrees<float>(240.0f), 0.027450980392156876f, 1.0f, 1.0f);}
    static constexpr HsvColor gold() {return HsvColor(Degrees<float>(50.588235294117645f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor dark_green() {return HsvColor(Degrees<float>(120.0f), 1.0f, 0.39215686274509803f, 1.0f);}
    static constexpr HsvColor bisque() {return HsvColor(Degrees<float>(32.54237288135594f), 0.2313725490196078f, 1.0f, 1.0f);}
    static constexpr HsvColor pure_red() {return HsvColor(Degrees<float>(0.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor indigo() {return HsvColor(Degrees<float>(274.6153846153846f), 1.0f, 0.5098039215686274f, 1.0f);}
    static constexpr HsvColor white() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor medium_slate_blue() {return HsvColor(Degrees<float>(248.50746268656715f), 0.5630252100840336f, 0.9333333333333333f, 1.0f);}
    static constexpr HsvColor sea_green() {return HsvColor(Degrees<float>(146.45161290322582f), 0.6690647482014388f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor forest_green() {return HsvColor(Degrees<float>(120.0f), 0.7553956834532375f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor cornflower_blue() {return HsvColor(Degrees<float>(218.54014598540147f), 0.5780590717299579f, 0.9294117647058824f, 1.0f);}
    static constexpr HsvColor sky_blue() {return HsvColor(Degrees<float>(197.4f), 0.42553191489361697f, 0.9215686274509803f, 1.0f);}
    static constexpr HsvColor spring_green() {return HsvColor(Degrees<float>(149.88235294117646f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor crimson() {return HsvColor(Degrees<float>(348.0f), 0.9090909090909092f, 0.8627450980392157f, 1.0f);}
    static constexpr HsvColor silver() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor blue_violet() {return HsvColor(Degrees<float>(271.1475409836066f), 0.8097345132743362f, 0.8862745098039215f, 1.0f);}
    static constexpr HsvColor dark_violet() {return HsvColor(Degrees<float>(282.08530805687207f), 1.0f, 0.8274509803921568f, 1.0f);}
    static constexpr HsvColor cyan() {return HsvColor(Degrees<float>(180.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor dim_gray() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor antique_white() {return HsvColor(Degrees<float>(34.28571428571427f), 0.13999999999999996f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor pure_blue() {return HsvColor(Degrees<float>(240.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor plum() {return HsvColor(Degrees<float>(300.0f), 0.27601809954751133f, 0.8666666666666667f, 1.0f);}
    static constexpr HsvColor navajo_white() {return HsvColor(Degrees<float>(35.853658536585364f), 0.32156862745098036f, 1.0f, 1.0f);}
    static constexpr HsvColor cadet_blue() {return HsvColor(Degrees<float>(181.84615384615384f), 0.40625f, 0.6274509803921569f, 1.0f);}
    static constexpr HsvColor dark_olive_green() {return HsvColor(Degrees<float>(82.0f), 0.5607476635514018f, 0.4196078431372549f, 1.0f);}
    static constexpr HsvColor light_yellow() {return HsvColor(Degrees<float>(60.0f), 0.1215686274509804f, 1.0f, 1.0f);}
    static constexpr HsvColor brown() {return HsvColor(Degrees<float>(0.0f), 0.7454545454545455f, 0.6470588235294118f, 1.0f);}
    static constexpr HsvColor lemon_chiffon() {return HsvColor(Degrees<float>(53.999999999999986f), 0.196078431372549f, 1.0f, 1.0f);}
    static constexpr HsvColor aquamarine() {return HsvColor(Degrees<float>(159.84375f), 0.5019607843137255f, 1.0f, 1.0f);}
    static constexpr HsvColor fire_brick() {return HsvColor(Degrees<float>(0.0f), 0.8089887640449438f, 0.6980392156862745f, 1.0f);}
    static constexpr HsvColor medium_aquamarine() {return HsvColor(Degrees<float>(159.61165048543688f), 0.5024390243902439f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor misty_rose() {return HsvColor(Degrees<float>(6.000000000000034f), 0.11764705882352944f, 1.0f, 1.0f);}
    static constexpr HsvColor ivory() {return HsvColor(Degrees<float>(60.0f), 0.05882352941176472f, 1.0f, 1.0f);}
    static constexpr HsvColor papaya_whip() {return HsvColor(Degrees<float>(37.14285714285714f), 0.16470588235294115f, 1.0f, 1.0f);}
    static constexpr HsvColor pale_green() {return HsvColor(Degrees<float>(120.0f), 0.3944223107569721f, 0.984313725490196f, 1.0f);}
    static constexpr HsvColor hot_pink() {return HsvColor(Degrees<float>(330.0f), 0.5882352941176471f, 1.0f, 1.0f);}
    static constexpr HsvColor medium_purple() {return HsvColor(Degrees<float>(259.6261682242991f), 0.4885844748858447f, 0.8588235294117647f, 1.0f);}
    static constexpr HsvColor dark_gray() {return HsvColor(Degrees<float>(0.0f), 0.0f, 1.0f, 1.0f);}
    static constexpr HsvColor moccasin() {return HsvColor(Degrees<float>(38.10810810810811f), 0.2901960784313725f, 1.0f, 1.0f);}
    static constexpr HsvColor saddle_brown() {return HsvColor(Degrees<float>(24.999999999999996f), 0.8633093525179856f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor sienna() {return HsvColor(Degrees<float>(19.30434782608696f), 0.7187499999999999f, 0.6274509803921569f, 1.0f);}
    static constexpr HsvColor mint_cream() {return HsvColor(Degrees<float>(149.99999999999991f), 0.039215686274509776f, 1.0f, 1.0f);}
    static constexpr HsvColor light_green() {return HsvColor(Degrees<float>(120.0f), 0.39495798319327735f, 0.9333333333333333f, 1.0f);}
    static constexpr HsvColor tan() {return HsvColor(Degrees<float>(34.2857142857143f), 0.33333333333333326f, 0.8235294117647058f, 1.0f);}
    static constexpr HsvColor light_sky_blue() {return HsvColor(Degrees<float>(202.95652173913044f), 0.45999999999999996f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor light_pink() {return HsvColor(Degrees<float>(350.95890410958907f), 0.28627450980392155f, 1.0f, 1.0f);}
    static constexpr HsvColor medium_turquoise() {return HsvColor(Degrees<float>(177.8102189781022f), 0.6555023923444976f, 0.8196078431372549f, 1.0f);}
    static constexpr HsvColor lime() {return HsvColor(Degrees<float>(120.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor coral() {return HsvColor(Degrees<float>(16.114285714285714f), 0.6862745098039216f, 1.0f, 1.0f);}
    static constexpr HsvColor cornsilk() {return HsvColor(Degrees<float>(47.999999999999986f), 0.13725490196078427f, 1.0f, 1.0f);}
    static constexpr HsvColor aqua() {return HsvColor(Degrees<float>(180.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor honeydew() {return HsvColor(Degrees<float>(120.0f), 0.05882352941176472f, 1.0f, 1.0f);}
    static constexpr HsvColor deep_sky_blue() {return HsvColor(Degrees<float>(195.05882352941177f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor indian_red() {return HsvColor(Degrees<float>(0.0f), 0.551219512195122f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor purple() {return HsvColor(Degrees<float>(300.0f), 1.0f, 0.5019607843137255f, 1.0f);}
    static constexpr HsvColor khaki() {return HsvColor(Degrees<float>(54.0f), 0.41666666666666663f, 0.9411764705882353f, 1.0f);}
    static constexpr HsvColor wheat() {return HsvColor(Degrees<float>(39.09090909090909f), 0.2693877551020409f, 0.9607843137254902f, 1.0f);}
    static constexpr HsvColor sandy_brown() {return HsvColor(Degrees<float>(27.56756756756757f), 0.6065573770491803f, 0.9568627450980393f, 1.0f);}
    static constexpr HsvColor lawn_green() {return HsvColor(Degrees<float>(90.47619047619048f), 1.0f, 0.9882352941176471f, 1.0f);}
    static constexpr HsvColor light_steel_blue() {return HsvColor(Degrees<float>(213.91304347826087f), 0.20720720720720723f, 0.8705882352941177f, 1.0f);}
    static constexpr HsvColor yellow() {return HsvColor(Degrees<float>(60.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor peach_puff() {return HsvColor(Degrees<float>(28.285714285714278f), 0.27450980392156865f, 1.0f, 1.0f);}
    static constexpr HsvColor medium_orchid() {return HsvColor(Degrees<float>(288.0952380952381f), 0.5971563981042654f, 0.8274509803921568f, 1.0f);}
    static constexpr HsvColor fuchsia() {return HsvColor(Degrees<float>(300.0f), 1.0f, 1.0f, 1.0f);}
    static constexpr HsvColor dodger_blue() {return HsvColor(Degrees<float>(209.6f), 0.8823529411764706f, 1.0f, 1.0f);}
    static constexpr HsvColor yellow_green() {return HsvColor(Degrees<float>(79.74193548387098f), 0.7560975609756098f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor light_blue() {return HsvColor(Degrees<float>(194.73684210526315f), 0.24782608695652172f, 0.9019607843137255f, 1.0f);}
    static constexpr HsvColor light_sea_green() {return HsvColor(Degrees<float>(176.71232876712327f), 0.8202247191011236f, 0.6980392156862745f, 1.0f);}
    static constexpr HsvColor seashell() {return HsvColor(Degrees<float>(24.705882352941195f), 0.06666666666666665f, 1.0f, 1.0f);}
    static constexpr HsvColor snow() {return HsvColor(Degrees<float>(0.0f), 0.019607843137254943f, 1.0f, 1.0f);}
    static constexpr HsvColor royal_blue() {return HsvColor(Degrees<float>(225.0f), 0.7111111111111111f, 0.8823529411764706f, 1.0f);}
    static constexpr HsvColor slate_gray() {return HsvColor(Degrees<float>(210.0f), 0.2222222222222222f, 0.5647058823529412f, 1.0f);}
    static constexpr HsvColor pale_goldenrod() {return HsvColor(Degrees<float>(54.70588235294117f), 0.28571428571428575f, 0.9333333333333333f, 1.0f);}
    static constexpr HsvColor peru() {return HsvColor(Degrees<float>(29.577464788732396f), 0.6926829268292682f, 0.803921568627451f, 1.0f);}
    static constexpr HsvColor medium_violet_red() {return HsvColor(Degrees<float>(322.24719101123594f), 0.8944723618090452f, 0.7803921568627451f, 1.0f);}
    static constexpr HsvColor medium_spring_green() {return HsvColor(Degrees<float>(156.96f), 1.0f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor dark_khaki() {return HsvColor(Degrees<float>(55.609756097560975f), 0.4338624338624339f, 0.7411764705882353f, 1.0f);}
    static constexpr HsvColor salmon() {return HsvColor(Degrees<float>(6.176470588235292f), 0.5439999999999999f, 0.9803921568627451f, 1.0f);}
    static constexpr HsvColor dark_cyan() {return HsvColor(Degrees<float>(180.0f), 1.0f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor dark_blue() {return HsvColor(Degrees<float>(240.0f), 1.0f, 0.5450980392156862f, 1.0f);}
    static constexpr HsvColor dark_sea_green() {return HsvColor(Degrees<float>(120.0f), 0.23936170212765961f, 0.7372549019607844f, 1.0f);}
    static constexpr HsvColor thistle() {return HsvColor(Degrees<float>(300.0f), 0.11574074074074073f, 0.8470588235294118f, 1.0f);}
    static constexpr HsvColor light_slate_gray() {return HsvColor(Degrees<float>(210.0f), 0.22222222222222218f, 0.6f, 1.0f);}
    static constexpr HsvColor old_lace() {return HsvColor(Degrees<float>(39.130434782608695f), 0.09090909090909093f, 0.9921568627450981f, 1.0f);}
    static constexpr HsvColor orchid() {return HsvColor(Degrees<float>(302.2641509433962f), 0.4862385321100917f, 0.8549019607843137f, 1.0f);}
    static constexpr HsvColor burly_wood() {return HsvColor(Degrees<float>(33.79310344827586f), 0.3918918918918919f, 0.8705882352941177f, 1.0f);}
    static constexpr HsvColor light_salmon() {return HsvColor(Degrees<float>(17.142857142857142f), 0.5215686274509803f, 1.0f, 1.0f);}

protected:
private:
};


#endif
    

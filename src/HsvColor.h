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
protected:
private:
};


#endif
    

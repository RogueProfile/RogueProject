#include "Color.h"

#include <array>
#include <algorithm>

#include "HsvColor.h"


HsvColor Color::to_hsv() const
{
    HsvColor rval = HsvColor(Degrees<float>(0.f), 0.f, 0.f, alpha);
    std::array<float, 3> rgb {red, green, blue};
    auto minmax = std::minmax_element(rgb.begin(), rgb.end());
    float delta = minmax.second - minmax.first;

    if (*minmax.second != 0 )
    {
        rval.hue.value = delta / *minmax.second;
    }

    else 
    {
        rval.saturation = 0;
        rval.hue.value = 0;
        rval.value = 0;
        return rval;
    }

    if (red == *minmax.second)
    {
        rval.hue.value = 60 * ((green - blue) / delta);
    }
    else if (green == *minmax.second)
    {
        rval.hue.value = 60 * (2 + (blue - red ) / delta);
    }
    else 
    {
        rval.hue.value = 60 * (4 + (red - green) / delta);
    }

    rval.hue.clamp_value();
    return rval; 
}

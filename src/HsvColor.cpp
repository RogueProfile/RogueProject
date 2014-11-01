#include <algorithm>
#include <array>
#include <cmath>

#include "Angle.h"
#include "Color.h"
#include "HsvColor.h"

constexpr Color HsvColor::to_rgb()
{
     Color rval = Color(0.f, 0.f, 0.f); 
     
     if ( saturation == 0 ) {
        rval.red = value;
        rval.green = value;
        rval.blue = value;
        return rval;
     }

     float sector = hue.value / 60;
     int integral_sector = sector;
     float fractional_sector = sector - integral_sector;
     float component_one = value * ( 1 - saturation );
     float component_two = value * ( 1 - saturation * fractional_sector );
     float component_three = value * ( 1 - saturation * ( 1 - fractional_sector));

     switch ( integral_sector ){
         case 0:
            rval.red = value;
            rval.green = component_three;
            rval.blue = component_two;
            break;
         case 1:
			rval.red = component_two;
			rval.green = value;
			rval.blue = component_one;
			break;
		case 2:
			rval.red = component_one;
			rval.green = value;
			rval.blue = component_three;
			break;
		case 3:
			rval.red = component_one;
			rval.green = component_two;
			rval.blue = value;
			break;
		case 4:
			rval.red = component_three;
			rval.green = component_one;
			rval.blue = value;
			break;
		default:		// case 5:
			rval.red = value;
			rval.green = component_one;
			rval.blue = component_two;
			break;
     }
    return rval;

}


constexpr HsvColor HsvColor::from_rgb(const Color& that){

    HsvColor rval = HsvColor(Degrees<float>(0.f), 0.f, 0.f, 0.f);
    std::array<float, 3> rgb {that.red, that.green, that.blue};
    auto minmax = std::minmax_element(rgb.begin(), rgb.end());
    float delta = minmax.second - minmax.first;
    
   if ( *minmax.second != 0 )
      rval.hue.value = delta / *minmax.second;
   else {
      rval.saturation = 0;
      rval.hue.value = 0;
      rval.value = 0;
      return rval;
   }

   if (that.red == *minmax.second){
       rval.hue.value = 60 * ( ( that.green - that.blue ) / delta );
   }
   else if (that.green == *minmax.second){
       rval.hue.value = 60 * ( 2 + ( that.blue - that.red ) / delta );
   }
   else {
       rval.hue.value = 60 * ( 4 + ( that.red - that.green ) / delta );
   }
         
    rval.hue.clamp_value();
    return rval; 


}
 

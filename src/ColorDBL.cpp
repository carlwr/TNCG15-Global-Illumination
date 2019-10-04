#include "ColorDBL.h"


std::string ColorDBL::toString(){
    int RGBr = 255*r;
    int RGBg = 255*g;
    int RGBb = 255*b;
    return std::to_string(RGBr) + " " + std::to_string(RGBg) + " " + std::to_string(RGBb); 
}

int ColorDBL::getRedAsRGB(){
    return 255*r;
}

int ColorDBL::getGreenAsRGB(){
    return 255*g;
}

int ColorDBL::getBlueAsRGB(){
    return 255*b;
}

ColorDBL ColorDBL::mergeColor(ColorDBL color){
    return ColorDBL(r * color.getRed(), g*color.getGreen(), b*color.getBlue());
}
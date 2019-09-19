#include "Pixel.h"



std::string Pixel::toString(){
    return  color.toString();
    //return ray.toString();
}

std::vector<int> Pixel::getColorAsRGB(){
    
    return std::vector<int>{color.getRedAsRGB(), color.getGreenAsRGB(), color.getBlueAsRGB()};
}

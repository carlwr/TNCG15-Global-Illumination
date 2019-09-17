#include "../include/Pixel.h"

namespace TNCG15{
    Pixel::Pixel(Ray pixelRay, ColorDBL pixelColor){
        color = pixelColor;
        ray = pixelRay;
    }

    std::string Pixel::toString(){
        return ray.toString();
    }
}
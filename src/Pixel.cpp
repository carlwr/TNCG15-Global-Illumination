#include "Pixel.h"


TNCG15::Pixel::Pixel(Ray pixelRay, ColorDBL pixelColor){
    color = pixelColor;
    ray = pixelRay;
}

std::string TNCG15::Pixel::toString(){
    return "hejhej";
    //return ray.toString();
}

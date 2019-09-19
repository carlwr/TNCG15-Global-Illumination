#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include "Ray.h"
#include "ColorDBL.h"
#include <iostream>
#include <vector>


    
class Pixel{
    public:
        Pixel( ColorDBL pColor, Ray pRay) : color{pColor}, ray{pRay}
        {

        }
        std::string toString();
        Ray getRay(){return ray;}
        void setColor(ColorDBL clr){color = clr;}
        std::vector<int> getColorAsRGB();
    private:
        ColorDBL color;
        Ray ray;
};



#endif
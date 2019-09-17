#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include "Ray.h"
#include "ColorDBL.h"

namespace TNCG15{
    
    class Pixel{
        public:
            Pixel(Ray, ColorDBL);
            std::string toString();
        private:
            ColorDBL color;
            Ray ray;
    };

}

#endif
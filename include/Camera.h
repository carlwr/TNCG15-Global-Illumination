#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Pixel.h"
#include <iostream>

namespace TNCG15{

    class Camera{
        public:
            Camera(int, int);

            Pixel getPixel(int x){
                std::cout << std::to_string(x);
                return *pixels.at(x);
            }

            std::string toString();

        private:
            const glm::vec3 EYE_ONE = glm::vec3(-2.0f,0.0f,0.0f);
            const float CAMERA_PLANE_X_COORD = 0.0f;
            std::vector<Pixel*> initPixels(int, int);
            std::vector<Pixel*> pixels;

    };

}

#endif
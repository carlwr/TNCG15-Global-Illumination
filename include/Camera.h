#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Pixel.h"
#include "Scene.h"
#include <iostream>

class Camera{
    public:
        Camera(int w, int h);
        

        Pixel getPixel(int x){
            std::cout << std::to_string(x);
            return pixels.at(x);
        }

        std::vector<Pixel> getPixels(){return pixels;}
        void toString();
        void createImage();
        void castRays(Scene scene);

    private:
        int width, height;
        std::vector<Pixel> pixels;
        glm::vec3 EYE_ONE = glm::vec3(-2.0f,0.0f,0.0f);
        float CAMERA_PLANE_X_COORD = 0.0f;
        void initPixels(int, int);

};



#endif
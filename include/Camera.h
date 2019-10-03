#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Pixel.h"
#include "Scene.h"
#include <iostream>

class Camera{
    public:
        Camera(int w, int h);
        std::vector<Pixel> getPixels(){return pixels;}
        void toString();
        void createImage();
        void castRays(Scene scene);
        glm::vec3 getMaxRGB();

    private:
        int width, height;
        std::vector<Pixel> pixels;
        glm::vec3 EYE_ONE = glm::vec3(-1.0f,0.0f,0.0f);
        float CAMERA_PLANE_X_COORD = 0.0f;
        void initPixels(int, int);

};



#endif
#include "Camera.h"

TNCG15::Camera::Camera(int width, int height){
    pixels = initPixels(width, height);
}

std::vector<TNCG15::Pixel*> TNCG15::Camera::initPixels(int width, int height){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            float pixelYCoord = i/width;
            float pixelZCoord = j/height;
            Ray ray(EYE_ONE ,glm::vec3(CAMERA_PLANE_X_COORD, pixelYCoord, pixelZCoord));
            Pixel* p = new Pixel(ray, ColorDBL(1.,1.,1.));
            pixels.push_back(p);
            
        }
    }
}

std::string TNCG15::Camera::toString(){
    return "HOLA";
}



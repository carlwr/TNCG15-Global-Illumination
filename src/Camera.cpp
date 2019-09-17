#include "../include/Camera.h"

namespace TNCG15{

    Camera::Camera(int width, int height){
        pixels = initPixels(width, height);
    }

    std::vector<Pixel> Camera::initPixels(int width, int height){
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                float pixelYCoord = i/width;
                float pixelZCoord = j/height;
                Ray ray(EYE_ONE ,glm::vec3(CAMERA_PLANE_X_COORD, pixelYCoord, pixelZCoord));
                Pixel p(ray, ColorDBL(1.,1.,1.));
                pixels.push_back(p);
                
            }
        }
    }


}
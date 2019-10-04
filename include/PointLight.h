#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "glm/vec3.hpp"

class PointLight{
    public: 
        PointLight(glm::vec3 p):position{p}{

        }
        glm::vec3 getPosition(){return position;}

    private:
        glm::vec3 position;

};


#endif
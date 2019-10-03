#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "glm/vec3.hpp"
#include "ColorDBL.h"

class Intersection{
    public:
        Intersection(): color{0,0,0}{

        };
        glm::vec3 position;
        glm::vec3 normal;
        ColorDBL color;
        float distance;
};

#endif
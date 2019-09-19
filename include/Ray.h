#ifndef RAY_H
#define RAY_H

#include "glm/vec3.hpp"
#include "glm/geometric.hpp"
#include "ColorDBL.h"
#include <string>
#include <iostream>
   
class Ray{
    public:
        Ray();
        Ray(glm::vec3 start, glm::vec3 end);
        std::string toString();
        glm::vec3 getDirection(){return direction;}
        glm::vec3 getStart(){return startPoint;}

    void setColor(const ColorDBL &clr){color = clr;}
        
    private: 
        glm::vec3 startPoint;
        glm::vec3 endPoint;
        glm::vec3 direction;
        ColorDBL color{1.,1.,0.};

};


#endif
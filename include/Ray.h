#ifndef RAY_H
#define RAY_H

#include "glm/vec3.hpp"
#include "Triangle.h"
#include <string>

namespace TNCG15{
    
    class Ray{
        public:
            Ray();
            Ray(glm::vec3 start, glm::vec3 end);
            std::string toString();
        private: 
            glm::vec3 startPoint;
            glm::vec3 endPoint;
            Triangle triangleInPath;
            ColorDBL color;

    };

}
#endif
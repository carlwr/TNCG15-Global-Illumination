#include "../include/Triangle.h"

namespace TNCG15{
    
    Triangle::Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c, ColorDBL dblColor ){
        first = a;
        second = b;
        third = c;
        color = dblColor;
        normal = glm::normalize(glm::cross(b-a, c-a));

    }
}
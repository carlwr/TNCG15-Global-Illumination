#include "../include/Ray.h"

namespace TNCG15{

    Ray::Ray(glm::vec3 start, glm::vec3 end)
    {
        startPoint = start;
        endPoint = end;
    }

    std::string Ray::toString(){
        return std::to_string(endPoint.x);
    }
}
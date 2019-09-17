#include "Ray.h"


TNCG15::Ray::Ray(glm::vec3 start, glm::vec3 end)
{
    startPoint = start;
    endPoint = end;
}
TNCG15::Ray::Ray()
{
    
}

std::string TNCG15::Ray::toString(){
    return std::to_string(endPoint.x);
}

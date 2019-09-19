#include "Ray.h"


Ray::Ray(glm::vec3 start, glm::vec3 end): startPoint{start}, endPoint{end}
{

    std::cout << start.x << " " << start.y << " " << start.z << std::endl;
    std::cout << end.x << " " << end.y << " " << end.z << std::endl;
    direction = glm::normalize(endPoint - startPoint);
    std::cout << direction.x << " " << direction.y << " " << direction.z << std::endl;
}

std::string Ray::toString(){
    return std::to_string(endPoint.x) + " " +   std::to_string(endPoint.y) + " " + std::to_string(endPoint.z);
}

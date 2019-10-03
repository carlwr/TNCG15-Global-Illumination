#include "Sphere.h"

Sphere::Sphere(glm::vec3 p, ColorDBL c, float r): SceneObject(p, c, r){
    radius = r;
}

std::vector<Intersection> Sphere::intersection(Ray& ray){

    std::vector<Intersection> intersections = {};
    glm::vec3 normalizedRayDirection = glm::normalize(ray.getDirection());
    glm::vec3 rayOrigin = ray.getStart();
    glm::vec3 sphereCenter = position;


    //b=2l·(o−c)
    float b = glm::dot((2.0f*normalizedRayDirection), (rayOrigin-sphereCenter));

    //c=(o−c)·(o−c)−r2
    float c = glm::dot(rayOrigin-sphereCenter, rayOrigin-sphereCenter)-glm::pow(radius, 2);

    float firstIntersectionDistance = -b / 2.0f;
    float secondIntersectionDistance = firstIntersectionDistance;
    float bsqrt = glm::sqrt(glm::pow(firstIntersectionDistance, 2) - c);
    firstIntersectionDistance += bsqrt;
    secondIntersectionDistance -= bsqrt;
    
    Intersection intersection;

    if(bsqrt < 0.00000000000000001){

       return intersections;
    } 
    bsqrt = glm::sqrt(bsqrt);

   if(firstIntersectionDistance <= 0 && secondIntersectionDistance <= 0){

       return intersections;
   }
   else if(secondIntersectionDistance < firstIntersectionDistance) {
       intersection.position = rayOrigin + secondIntersectionDistance*normalizedRayDirection;
       intersection.normal = glm::normalize((rayOrigin + secondIntersectionDistance*normalizedRayDirection) - sphereCenter);
       intersection.distance = glm::length((rayOrigin + secondIntersectionDistance*normalizedRayDirection) - rayOrigin);
       intersection.color = color;
       intersections.push_back(intersection);
       return intersections;
   }
   else if(firstIntersectionDistance < secondIntersectionDistance) {
       
       intersection.position = rayOrigin + secondIntersectionDistance*normalizedRayDirection;
       intersection.normal = glm::normalize((rayOrigin + secondIntersectionDistance*normalizedRayDirection) - sphereCenter);
       intersection.distance = glm::length((rayOrigin + secondIntersectionDistance*normalizedRayDirection) - rayOrigin);
       intersection.color = color;
       intersections.push_back(intersection);
       return intersections;
   }
   else {
       intersection.position = rayOrigin + secondIntersectionDistance*normalizedRayDirection;
       intersection.normal = glm::normalize((rayOrigin + secondIntersectionDistance*normalizedRayDirection) - sphereCenter);
       intersection.distance = glm::length((rayOrigin + secondIntersectionDistance*normalizedRayDirection) - rayOrigin);
       intersection.color = color;
       intersections.push_back(intersection);

       return intersections;
   }


}
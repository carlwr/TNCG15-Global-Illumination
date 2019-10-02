#include "Triangle.h"

// Using Möller Trumbore algorithm
// A point on the triangle is given by T(u,v) = (1-u-v)*v0 + u*v1 + v*v2
// => T = u*E1 + v*E2 - t*D
// were E1 = v1 - v0, E2 = v2 - v0, D = Ray Direction
bool Triangle::rayIntersection(Ray& ray, Intersection& intersection){
    // u,v to solve for
    float u, v;
    glm::vec3 intersectionPoint;
    //https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-rendering-a-triangle/moller-trumbore-ray-triangle-intersection
    
    //triangle edges
    glm::vec3 E1 = v1 - v0; 
    glm::vec3 E2 = v2 - v0;

    glm::vec3 D = ray.getDirection();
    glm::vec3 edgeNormal = glm::cross(D,E2); 
    
    float det = glm::dot(E1,edgeNormal);
    float invDet = 1 / det; 

    glm::vec3 rayV0 = ray.getStart() - v0; 

    // Calculate u
    u = glm::dot(rayV0,edgeNormal) * invDet; 
    if(u < 0 || u > 1){

        return false; //no intersection
    }


    glm::vec3 Q = glm::cross(rayV0,E1); 

    //calculate v
    v = glm::dot(D, Q) * invDet;
    if(v < 0 || v > 1 || u + v > 1){

        return false; //no intersection
    }
    
    float t = glm::dot(E2,Q) * invDet;


    if ( t < 0){

       return false; //no intersection
    } 
    intersection.position = ray.getStart() + t*D;
    // intersection = glm::vec3(ray.getStart() + t*D);
    return true;
}

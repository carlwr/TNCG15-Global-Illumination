
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "glm/vec3.hpp"
#include "ColorDBL.h"
#include "Ray.h"
#include "glm/geometric.hpp"
#include "Intersection.h"
#include <iostream>

class Triangle{
    public:
        Triangle();
        Triangle(glm::vec3 a, glm::vec3 b , glm::vec3 c , ColorDBL tColor) : v0{a}, v1{b}, v2{c}, color{tColor}{
            normal = glm::normalize(glm::cross(b-a, c-a));
        }
        glm::vec3 getNormal(){return normal;}
        bool rayIntersection(Ray& ray, Intersection& intersection);
        ColorDBL getColor(){return color;}
    private:
        const glm::vec3 v0, v1, v2;
        ColorDBL color;
        glm::vec3 normal;

        //Computes the intersection between a Ray and the Triangle using the Möller-Trumbore algorithm.

};


#endif
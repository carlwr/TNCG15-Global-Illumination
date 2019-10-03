#ifndef SPHERE_H
#define SPHERE_H

#include "SceneObject.h"
#include <vector>

class Sphere : public SceneObject{
    public:
        Sphere();
        Sphere(glm::vec3, ColorDBL, float); 
        std::vector<Intersection> intersection(Ray& ray);
    private:
        float radius;
};


#endif

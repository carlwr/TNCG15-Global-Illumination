#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H


#include "glm/vec3.hpp"
#include "ColorDBL.h"
#include "Ray.h"

class SceneObject{
    
    public:
        bool intersection(Ray& ray, glm::vec3& intersection);
    private:



};




#endif
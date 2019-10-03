#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H


#include "glm/vec3.hpp"
#include "ColorDBL.h"
#include "Ray.h"
#include "Triangle.h"
#include <vector>


class SceneObject{
    public:
        SceneObject(){
        };
        SceneObject(glm::vec3 p, ColorDBL c, float size){
            color = c;
            position = p;
        }
        virtual std::vector<Intersection> intersection(Ray& ray){
            
        };
    protected:
        glm::vec3 position;
        ColorDBL color;


};




#endif
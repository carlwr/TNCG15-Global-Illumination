#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "SceneObject.h"
#include "Triangle.h"
#include <vector>

class Tetrahedron : public SceneObject{
    public:
        Tetrahedron();
        Tetrahedron(glm::vec3, ColorDBL, float); 
        std::vector<Intersection> intersection(Ray& ray);
    private:
        Triangle* triangles[3]{};

};


#endif

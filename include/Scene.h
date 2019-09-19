#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Triangle.h"
#include "Ray.h"

class Scene{
    public:
        void setTriangles(std::vector<Triangle>);
        Triangle getIntersections(Ray ray);

    private:
        std::vector<Triangle> triangles;
};

#endif
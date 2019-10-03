#ifndef SCENE_H
#define SCENE_H

#include "Intersection.h"
#include "SceneObject.h"
#include <vector>
#include <list>
#include "Ray.h"
#include "Triangle.h"



class Scene{
    public:
        void setTriangles(std::vector<Triangle>);
        std::list<Intersection> getIntersections(Ray ray);
        void addSceneObject(SceneObject* sceneObject);

    private:
        std::vector<Triangle> triangles;
        std::vector<SceneObject*> sceneObjects;
};

#endif
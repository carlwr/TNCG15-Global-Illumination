#include "Scene.h"

std::list<Intersection> Scene::getIntersections(Ray ray){
    std::list<Intersection> intersections = {};
    for(int i = 0; i < triangles.size(); i++){
        Intersection intersection;
        if(triangles[i].rayIntersection(ray, intersection)){
            intersection.color = triangles[i].getColor();
            intersection.normal = triangles[i].getNormal();;
            
            intersections.push_back(intersection);
        }
    }
    return intersections;
}

void Scene::setTriangles(std::vector<Triangle> roomTriangles){
        for (int i=0; i<roomTriangles.size(); i++) 
        triangles.push_back(roomTriangles[i]);
}


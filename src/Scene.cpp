#include "Scene.h"

std::list<Intersection> Scene::getIntersections(Ray ray){
    std::list<Intersection> intersections = {};
    //getintersections in scene
    for(int i = 0; i < triangles.size(); i++){
        Intersection intersection;
        if(triangles[i].rayIntersection(ray, intersection)){
            intersection.color = triangles[i].getColor();
            intersection.normal = triangles[i].getNormal();;
            
            intersections.push_back(intersection);
        }
    }
    for(int i = 0; i < sceneObjects.size(); i++){

        std::vector<Intersection> sOIntersections = (*sceneObjects[i]).intersection(ray);
        for(int i = 0; i < sOIntersections.size(); i++){

            intersections.push_back(sOIntersections[i]);
        }
    }

    //sort vector list by distance to intersection
    intersections.sort([](const auto &a, const auto &b) {
        return  a.distance < b.distance;
    });

    

    return intersections;
}

void Scene::setTriangles(std::vector<Triangle> roomTriangles){
        for (int i=0; i<roomTriangles.size(); i++) 
        triangles.push_back(roomTriangles[i]);
}

void Scene::addSceneObject(SceneObject* sceneObject){
    sceneObjects.push_back(sceneObject);

}


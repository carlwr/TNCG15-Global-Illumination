#include "Scene.h"

Triangle Scene::getIntersections(Ray ray){
    for(int i = 0; i < triangles.size(); i++){
        glm::vec3 intersection;
        if(triangles[i].rayIntersection(ray, intersection)){
            return triangles[i];
        }

        
    }
}

void Scene::setTriangles(std::vector<Triangle> roomTriangles){
        for (int i=0; i<roomTriangles.size(); i++) 
        triangles.push_back(roomTriangles[i]);
}


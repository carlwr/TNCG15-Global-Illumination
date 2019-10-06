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

//Checks how much the light will contribute to the point color
ColorDBL Scene::shadowRayContribution(glm::vec3 point){
    for(PointLight* light : lights){
        glm::vec3 shadowRayDir = glm::normalize(light->getPosition() - point);
        Ray shadowRay{point, light->getPosition()};
        std::list<Intersection> intersections = getIntersections(shadowRay);
        if(intersections.front().distance < glm::distance(light->getPosition(), point)-0.1f ){
            std::cout << intersections.front().distance << " and " << glm::distance(light->getPosition(), point) << std::endl;
            //No interaction
            continue;
        }

        return ColorDBL{1,1,1};
    }
    return ColorDBL{0,0,0};  
}

void Scene::setTriangles(std::vector<Triangle> roomTriangles){
        for (int i=0; i<roomTriangles.size(); i++) 
        triangles.push_back(roomTriangles[i]);
}

void Scene::addSceneObject(SceneObject* sceneObject){
    sceneObjects.push_back(sceneObject);
}

void Scene::addLight(PointLight* light){
    lights.push_back(light);
}


#include "Tetrahedron.h"

Tetrahedron::Tetrahedron(glm::vec3 p, ColorDBL c, float size): SceneObject(p,c, size){
    glm::vec3 v1 = p + glm::vec3{size/2.0f,size/2.0f,0};
    glm::vec3 v2 = p + glm::vec3{size/2.0f,-size/2.0f,0};
    glm::vec3 v3 = p + glm::vec3{-size/2.0f,0,0};
    glm::vec3 v4 = p + glm::vec3{0,0,size/2.0f};

    Triangle t1{v2,v1,v4, c};
    Triangle t2{v3,v2,v4, c};
    Triangle t3{v1,v3,v4, c};

    triangles[0] =  new Triangle(t1);
    triangles[1] =  new Triangle(t2);
    triangles[2] =  new Triangle(t3);

}

std::vector<Intersection> Tetrahedron::intersection(Ray& ray){
    std::vector<Intersection> intersections = {};

    for(int i = 0; i < 3; i++){
        Intersection intersection;
        if((*triangles[i]).rayIntersection(ray, intersection)){

            intersection.color = (*triangles[i]).getColor();
            intersection.normal = (*triangles[i]).getNormal();;
            
            intersections.push_back(intersection);

        }
        
    }
    
    return intersections;
}

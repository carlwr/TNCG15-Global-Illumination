// //////////////////////////////////////////////////////////
// how to use TooJpeg: creating a JPEG file
// see https://create.stephan-brumme.com/toojpeg/
// compile: g++ example.cpp toojpeg.cpp -o example -std=c++11
 #include "Scene.h"
// #include "include/glm/vec3.hpp"
#include "Camera.h"

#include <iostream>
#include "Tetrahedron.h"
#include "Sphere.h"
#include "PointLight.h"
using namespace std;



std::vector<Triangle> buildTestRoom(){
    // b = bottom
    glm::vec3 A_b(0.f, 6.f, -5.f);
    glm::vec3 B_b(10.f, 6.f, -5.f);
    glm::vec3 C_b(13.f, 0.f, -5.f);
    glm::vec3 D_b(10.f, -6.f, -5.f);
    glm::vec3 E_b(0.f, -6.f, -5.f);
    glm::vec3 F_b(-3.f, 0.f, -5.f);

    // t = top
    glm::vec3 A_t(0.f, 6.f, 5.f);
    glm::vec3 B_t(10.f, 6.f, 5.f);
    glm::vec3 C_t(13.f, 0.f, 5.f);
    glm::vec3 D_t(10.f, -6.f, 5.f);
    glm::vec3 E_t(0.f, -6.f, 5.f);
    glm::vec3 F_t(-3.f, 0.f, 5.f);


    std::vector<Triangle> triangles{
    //Walls
    Triangle(B_t, D_b, D_t, ColorDBL(1.,0.,1.)),
    // Triangle(D_b, C_b, D_t, ColorDBL(1.,0.,1.)),


    // Triangle(B_t, C_t, C_b, ColorDBL(1.,0.,1.)),
    // Triangle(B_t, C_b, B_b, ColorDBL(1.,0.,1.)),

    // Triangle(A_t, B_t, B_b, ColorDBL(1.,1.,0.)),
    // Triangle(A_b, A_t, B_b, ColorDBL(1.,1.,0.)),
    
    // Triangle(E_b, D_b, E_t, ColorDBL(0.,1.,1.)),
    // Triangle(E_t, D_b, D_t, ColorDBL(0.,1.,1.)),

    // Triangle(B_b, E_b, A_b, ColorDBL(1.,1.,1.)),
    // Triangle(B_b, D_b, E_b, ColorDBL(1.,1.,1.)),

    // Triangle(B_t, E_t, A_t, ColorDBL(1.,1.,1.)),
    // Triangle(B_t, D_t, E_t, ColorDBL(1.,1.,1.)),


    // Triangle(B_t, D_t, C_t, ColorDBL(1.,1.,1.)),
    // Triangle(B_b, D_b, C_b, ColorDBL(1.,1.,1.)),

    

    // //Floor
    // Triangle(E_b, A_b, F_b, ColorDBL(1.,1.,1.)),
    // Triangle(E_b, A_b, D_b, ColorDBL(1.,1.,1.)),
    // Triangle(D_b, B_b, E_b, ColorDBL(1.,1.,1.)),
    // Triangle(D_b, C_b, B_b, ColorDBL(1.,1.,1.)),
    // //A-B   RED
    // //D-E  YELLOW
    // Triangle(D_b, E_t, D_t, ColorDBL(1.,1.,0.)),
    // Triangle(E_b, E_t, D_b, ColorDBL(1.,1.,0.)),

    // Triangle(A_b, B_t, A_t, ColorDBL(1.,0.,0.)),
    // Triangle(B_b, B_t, A_b, ColorDBL(1.,0.,0.))

    };

    return triangles;

}


std::vector<Triangle> buildBasicRoom(){
    //    A       B
    // F              C
    //    E       D

    
    // b = bottom
    glm::vec3 A_b(0.f, 6.f, -5.f);
    glm::vec3 B_b(10.f, 6.f, -5.f);
    glm::vec3 C_b(13.f, 0.f, -5.f);
    glm::vec3 D_b(10.f, -6.f, -5.f);
    glm::vec3 E_b(0.f, -6.f, -5.f);
    glm::vec3 F_b(-3.f, 0.f, -5.f);

    // t = top
    glm::vec3 A_t(0.f, 6.f, 5.f);
    glm::vec3 B_t(10.f, 6.f, 5.f);
    glm::vec3 C_t(13.f, 0.f, 5.f);
    glm::vec3 D_t(10.f, -6.f, 5.f);
    glm::vec3 E_t(0.f, -6.f, 5.f);
    glm::vec3 F_t(-3.f, 0.f, 5.f);

    //triangles right handed
    //1.(A_b, B_t, A_t)
    //
    //   A_t     B_t
    //    ^    ^  
    //    |   /   
    //    |  /    
    //   A_b     B_b
    
    //2. (B_b, B_t, A_b)
    //
    //   A_t     B_t
    //            ^
    //            |
    //            |
    //   A_b <-- B_b
    std::vector<Triangle> triangles{
    //Walls
    //A-B   RED
    Triangle(A_b, B_t, A_t, ColorDBL(1.,0.,0.)),
    Triangle(B_b, B_t, A_b, ColorDBL(1.,0.,0.)),
    //B-C  Green
    Triangle(B_b, C_t, B_t, ColorDBL(0.,1.,0.)),
    Triangle(C_b, C_t, B_b, ColorDBL(0.,1.,0.)),
    // //C-D  Blue
    Triangle(C_b, D_t, C_t, ColorDBL(0.,0.,1.)),
    Triangle(D_b, D_t, C_b, ColorDBL(0.,0.,1.)),
    // //D-E  YELLOW
    Triangle(D_b, E_t, D_t, ColorDBL(1.,1.,0.)),
    Triangle(E_b, E_t, D_b, ColorDBL(1.,1.,0.)),
    // //E-F  CYAN
    Triangle(E_b, F_t, E_t, ColorDBL(0.,1.,1.)),
    Triangle(F_b, F_t, E_b, ColorDBL(0.,1.,1.)),

    // //F-A  PURPLE
    Triangle(F_b, A_t, F_t, ColorDBL(1.,0.,1.)),
    Triangle(A_b, A_t, F_b, ColorDBL(1.,0.,1.)),

    // // //Floor
    Triangle(E_b, A_b, F_b, ColorDBL(1.,1.,1.)),
    Triangle(E_b, D_b, A_b, ColorDBL(1.,1.,1.)),
    Triangle(D_b, B_b, A_b, ColorDBL(1.,1.,1.)),
    Triangle(D_b, C_b, B_b, ColorDBL(1.,1.,1.)),


    // // //Roof
    Triangle(E_t, F_t, A_t, ColorDBL(0.5,0.5,0.5)),
    Triangle(E_t, A_t, D_t, ColorDBL(0.5,0.5,0.5)),
    Triangle(D_t, A_t, B_t, ColorDBL(0.5,0.5,0.5)),
    Triangle(D_t, B_t, C_t, ColorDBL(0.5,0.5,0.5))
    };

    return triangles;
}


int main()
{
    Scene scene{};
    scene.setTriangles(buildBasicRoom());
    SceneObject* tetra = new Tetrahedron(glm::vec3(5,0,-4), ColorDBL(0.5,0.2,0.9), 3.0f);
    // SceneObject* sphere = new Sphere(glm::vec3(7,0,0), ColorDBL(0.5,0.2,0.9), 2.0f);
    PointLight* light = new PointLight(glm::vec3(5,0,5));
    scene.addLight(light);
    // scene.addSceneObject(sphere);
    scene.addSceneObject(tetra);

    Camera camera(800,800);
    camera.castRays(scene);

    camera.createImage();

}
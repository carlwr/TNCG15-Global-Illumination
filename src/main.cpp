// //////////////////////////////////////////////////////////
// how to use TooJpeg: creating a JPEG file
// see https://create.stephan-brumme.com/toojpeg/
// compile: g++ example.cpp toojpeg.cpp -o example -std=c++11
 #include "Scene.h"
// #include "include/glm/vec3.hpp"
#include "Camera.h"

#include <iostream>
using namespace std;





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
    //B-C  BLUE
    Triangle(B_b, C_t, B_t, ColorDBL(0.,1.,0.)),
    Triangle(C_b, C_t, B_b, ColorDBL(0.,1.,0.)),
    //C-D  GREEN
    Triangle(C_b, D_t, C_t, ColorDBL(0.,0.,1.)),
    Triangle(D_b, D_t, C_b, ColorDBL(0.,0.,1.)),
    //D-E  YELLOW
    Triangle(D_b, E_t, D_t, ColorDBL(1.,1.,0.)),
    Triangle(E_b, E_t, D_b, ColorDBL(1.,1.,0.)),
    //E-F  CYAN
    Triangle(E_b, F_t, E_t, ColorDBL(0.,1.,1.)),
    Triangle(F_b, F_t, E_b, ColorDBL(0.,1.,1.)),
    //F-A  PURPLE
    Triangle(F_b, A_t, F_t, ColorDBL(1.,0.,1.)),
    Triangle(A_b, A_t, F_b, ColorDBL(1.,0.,1.)),

    //Floor
    Triangle(E_b, A_b, F_b, ColorDBL(1.,1.,1.)),
    Triangle(E_b, D_b, A_b, ColorDBL(1.,1.,1.)),
    Triangle(D_b, B_b, E_b, ColorDBL(1.,1.,1.)),
    Triangle(D_b, C_b, B_b, ColorDBL(1.,1.,1.)),


    //Roof
    Triangle(E_b, F_b, A_b, ColorDBL(1.,1.,1.)),
    Triangle(E_b, A_b, D_b, ColorDBL(1.,1.,1.)),
    Triangle(D_b, E_b, B_b, ColorDBL(1.,1.,1.)),
    Triangle(D_b, B_b, C_b, ColorDBL(1.,1.,1.))
    };

    return triangles;
}


int main()
{
    Scene scene{};
    scene.setTriangles(buildBasicRoom());
    
    int width;
    int height;
    std::cout << "Width: ";
    std::cin >> width;
    std::cout << "Height";
    std::cin >> height;

    Camera camera(width,height);

    camera.castRays(scene);

    camera.createImage();

}
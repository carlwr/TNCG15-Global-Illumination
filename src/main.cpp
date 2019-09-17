
// #include "src/Scene.cpp"
// #include "include/glm/vec3.hpp"
#include "Camera.h"
#include <iostream>
using namespace std;

using namespace TNCG15;

// std::vector<Triangle> buildBasicRoom(){
//     //    A       B
//     // F              C
//     //    E       D

    
//     // b = bottom
//     glm::vec3 A_b(0.f, 6.f, -5.f);
//     glm::vec3 B_b(10.f, 6.f, -5.f);
//     glm::vec3 C_b(13.f, 0.f, -5.f);
//     glm::vec3 D_b(10.f, -6.f, -5.f);
//     glm::vec3 E_b(0.f, -6.f, -5.f);
//     glm::vec3 F_b(-3.f, 0.f, -5.f);

//     // t = top
//     glm::vec3 A_t(0.f, 6.f, 5.f);
//     glm::vec3 B_t(10.f, 6.f, 5.f);
//     glm::vec3 C_t(13.f, 0.f, 5.f);
//     glm::vec3 D_t(10.f, -6.f, 5.f);
//     glm::vec3 E_t(0.f, -6.f, 5.f);
//     glm::vec3 F_t(-3.f, 0.f, 5.f);

//     //triangles right handed
//     //1.(A_b, B_t, A_t)
//     //
//     //   A_t     B_t
//     //    ^    ^  
//     //    |   /   
//     //    |  /    
//     //   A_b     B_b
    
//     //2. (B_b, B_t, A_b)
//     //
//     //   A_t     B_t
//     //            ^
//     //            |
//     //            |
//     //   A_b <-- B_b
//     std::vector<Triangle> triangles{
//     //Walls
//     //A-B
//     Triangle(A_b, B_t, A_t, ColorDBL(1.,1.,1.)),
//     Triangle(B_b, B_t, A_b, ColorDBL(1.,1.,1.)),
//     //B-C
//     Triangle(B_b, C_t, B_t, ColorDBL(1.,1.,1.)),
//     Triangle(C_b, C_t, B_b, ColorDBL(1.,1.,1.)),
//     //C-D
//     Triangle(C_b, D_t, C_t, ColorDBL(1.,1.,1.)),
//     Triangle(D_b, D_t, C_b, ColorDBL(1.,1.,1.)),
//     //D-E
//     Triangle(D_b, E_t, D_t, ColorDBL(1.,1.,1.)),
//     Triangle(E_b, E_t, D_b, ColorDBL(1.,1.,1.)),
//     //E-
//     Triangle(E_b, F_t, E_t, ColorDBL(1.,1.,1.)),
//     Triangle(F_b, F_t, E_b, ColorDBL(1.,1.,1.)),
//     //F-A
//     Triangle(F_b, A_t, F_t, ColorDBL(1.,1.,1.)),
//     Triangle(A_b, A_t, F_b, ColorDBL(1.,1.,1.)),

//     //Floor
//     Triangle(E_b, A_b, F_b, ColorDBL(1.,1.,1.)),
//     Triangle(E_b, D_b, A_b, ColorDBL(1.,1.,1.)),
//     Triangle(D_b, B_b, E_b, ColorDBL(1.,1.,1.)),
//     Triangle(D_b, C_b, B_b, ColorDBL(1.,1.,1.)),


//     //Roof
//     Triangle(E_b, F_b, A_b, ColorDBL(1.,1.,1.)),
//     Triangle(E_b, A_b, D_b, ColorDBL(1.,1.,1.)),
//     Triangle(D_b, E_b, B_b, ColorDBL(1.,1.,1.)),
//     Triangle(D_b, B_b, C_b, ColorDBL(1.,1.,1.))
//     };

//     return triangles;
// }


int main(){

    // Scene scene{};
    // scene.setTriangles(buildBasicRoom());

    Camera* camera = new Camera{5,5};

    // TestClass tc(1);
    //std::cout << "HEJ";
    std::cout << (*camera).getPixel(0).toString();

    return 0;
}

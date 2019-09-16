#include "include/ColorDBL.h"
#include "include/Triangle.h"
#include "include/Ray.h"
#include "include/Scene.h"
#include "include/glm/vec3.hpp"
#include <iostream>

using namespace TNCG15;

void buildBasicScene(){
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

    //Walls
    //A-B
    Triangle(A_b, B_t, A_t, ColorDBL(1.f,1.f,1.f));
    Triangle(B_b, B_t, A_b, ColorDBL(1.f,1.f,1.f));
    //B-C
    Triangle(B_b, C_t, B_t, ColorDBL(1.f,1.f,1.f));
    Triangle(C_b, C_t, B_b, ColorDBL(1.f,1.f,1.f));
    //C-D
    Triangle(C_b, D_t, C_t, ColorDBL(1.f,1.f,1.f));
    Triangle(D_b, D_t, C_b, ColorDBL(1.f,1.f,1.f));
    //D-E
    Triangle(D_b, E_t, D_t, ColorDBL(1.f,1.f,1.f));
    Triangle(E_b, E_t, D_b, ColorDBL(1.f,1.f,1.f));
    //E-F
    Triangle(E_b, F_t, E_t, ColorDBL(1.f,1.f,1.f));
    Triangle(F_b, F_t, E_b, ColorDBL(1.f,1.f,1.f));
    //F-A
    Triangle(F_b, A_t, F_t, ColorDBL(1.f,1.f,1.f));
    Triangle(A_b, A_t, F_b, ColorDBL(1.f,1.f,1.f));
}


int main(){
    buildBasicScene();
    return 0;
}

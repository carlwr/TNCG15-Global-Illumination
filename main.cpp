#include "src/Vector3.cpp"
#include "src/Ray.cpp"
#include <iostream>

using namespace TNCG15;

int main(){

    Ray* ray = new Ray();
    std::cout << "ray->start.x: " <<  ray->startPosition.x << std::endl;
    return 0;
}
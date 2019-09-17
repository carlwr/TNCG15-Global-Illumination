
#include "glm/vec3.hpp"
#include "glm/geometric.hpp"

namespace TNCG15{
    class Triangle{
        public:
            Triangle();
            Triangle(glm::vec3, glm::vec3, glm::vec3, ColorDBL);
            glm::vec3 rayIntersection();
        private:
            glm::vec3 first, second, third;
            ColorDBL color;
            glm::vec3 normal;

            //Computes the intersection between a Ray and the Triangle using the Möller-Trumbore algorithm.

    };
}
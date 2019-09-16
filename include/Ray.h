#include "glm/vec3.hpp"

namespace TNCG15{
    
    class Ray{
        public:

        private: 
            glm::vec3 startPoint;
            glm::vec3 endPoint;
            Triangle triangleInPath;
            ColorDBL color;

    };

}
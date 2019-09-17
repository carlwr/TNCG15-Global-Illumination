#include <vector>

namespace TNCG15{
    class Scene{
        public:
            void setTriangles(std::vector<Triangle>);
            Triangle getIntersections(Ray ray);

        private:
            std::vector<Triangle> triangles;
            //checks which triangle in the scene intersects with a ray.
    };
}
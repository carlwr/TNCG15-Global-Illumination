#include <vector>

namespace TNCG15{

    class Camera{
        public:
            Camera(int, int);

            Pixel getPixel(int x){
                return pixels[x];
            }

        private:
            const glm::vec3 EYE_ONE = glm::vec3(-2.0f,0.0f,0.0f);
            const float CAMERA_PLANE_X_COORD = 0.0f;
            std::vector<Pixel> initPixels(int, int);
            std::vector<Pixel> pixels;

    };

}
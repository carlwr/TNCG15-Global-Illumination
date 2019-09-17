#include <string>

namespace TNCG15{
    
    class Pixel{
        public:
            Pixel(Ray pixelRay, ColorDBL pixelColor);
            std::string toString();
        private:
            ColorDBL color;
            Ray ray;
    };

}
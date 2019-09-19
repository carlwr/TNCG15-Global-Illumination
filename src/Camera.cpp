#include "Camera.h"

#include "toojpeg.h"
#include <fstream>

// output file
std::ofstream myFile("example.jpg", std::ios_base::out | std::ios_base::binary);

// write a single byte compressed by tooJpeg
void myOutput(unsigned char byte)
{
  myFile << byte;
}


Camera::Camera(int w, int h): width{w}, height{h}{
    initPixels(width, height);
}

void Camera::initPixels(int width, int height){
    //loop though pixel width and height
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            //camera plane is 2x2 so every pixel needs to be 2/width x 2/height in size
            float deltaWidth = (float)2.f*i/width;
            float deltaHeight = (float)2.f*j/height;

            //make sure the ray goes through the center of the pixel
            float pixelCenterY = deltaWidth  - (1.f - 1.f/(float)width);
            float pixelCenterZ = deltaHeight - (1.f - 1.f/(float)height);

            Ray ray{EYE_ONE ,glm::vec3(CAMERA_PLANE_X_COORD, pixelCenterY, pixelCenterZ)};
            Pixel p ( ColorDBL{0,0,0}, ray);
            pixels.push_back(p);
            
        }
    }
}

void Camera::toString(){
    for(int i = 0; i < pixels.size(); i++){
        if( i != 0 && i % (width)  == 0){
            std::cout << std::endl;
            std::cout << std::endl;
        }
        std::cout << pixels[i].toString() << "    ";
    }
}

void Camera::createImage(){

  // RGB: one byte each for red, green, blue
  const auto bytesPerPixel = 3;
  // allocate memory
  auto image = new unsigned char[width * height * bytesPerPixel];
  // create a nice color transition (replace with your code)
  
    for(int i = 0; i < pixels.size(); i++){
        // if( i != 0 && i % (width)  == 0){
        //     std::cout << std::endl;
        //     std::cout << std::endl;
        // }
        auto offset = i * bytesPerPixel;
        image[offset    ] = pixels[i].getColorAsRGB()[0];
        image[offset + 1] = pixels[i].getColorAsRGB()[1];
        image[offset + 2] = pixels[i].getColorAsRGB()[2];

        // std::cout << pixels[i].toString() << "    ";
    }
    std::cout << std::endl;

    // start JPEG compression
    // note: myOutput is the function defined in line 18, it saves the output in example.jpg
    // optional parameters:
    const bool isRGB      = true;  // true = RGB image, else false = grayscale
    const auto quality    = 90;    // compression quality: 0 = worst, 100 = best, 80 to 90 are most often used
    const bool downsample = false; // false = save as YCbCr444 JPEG (better quality), true = YCbCr420 (smaller file)
    const char* comment = "TooJpeg example image"; // arbitrary JPEG comment
    auto ok = TooJpeg::writeJpeg(myOutput, image, width, height, isRGB, quality, downsample, comment);
    delete[] image;
    // error => exit code 1
}

void Camera::castRays(Scene scene){
    for(int i = 0; i < pixels.size(); i++){
        Triangle t = scene.getIntersections(pixels[i].getRay());
        pixels[i].setColor(t.getColor());
    }
}



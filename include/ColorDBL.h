#ifndef COLORDBL_H
#define COLORDBL_H

#include <string>


class ColorDBL{
    public: 
        ColorDBL(double red, double green, double blue): r{red}, g{green}, b{blue}{}
        ColorDBL(){

        }
        int getRedAsRGB();
        int getGreenAsRGB();
        int getBlueAsRGB();
        std::string toString();

    private:
        double r{};
        double g{};
        double b{};
};



#endif
#ifndef COLORDBL_H
#define COLORDBL_H

#include <string>


class ColorDBL{
    public: 
        ColorDBL(double red, double green, double blue): r{red}, g{green}, b{blue}{}
        ColorDBL(){

        }
        ColorDBL mergeColor(ColorDBL);
        int getRedAsRGB();
        int getGreenAsRGB();
        int getBlueAsRGB();
        std::string toString();

        double getRed(){return r;}
        double getGreen(){return g;}
        double getBlue(){return b;}


    private:
        double r{};
        double g{};
        double b{};
};



#endif
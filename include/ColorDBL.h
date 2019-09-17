#ifndef COLORDBL_H
#define COLORDBL_H



namespace TNCG15{
    class ColorDBL{
        public: 
            ColorDBL(double red, double green, double blue);
            ColorDBL();
        private:
            double r,g,b;
    };

}

#endif
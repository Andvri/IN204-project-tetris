#ifndef FIGURE_CLASS 
#define FIGURE_CLASS
#include "fiches.hpp"
#include <random>

class Figure{
public:
        //Constructeur
    Figure(int shape)
        : shape(static_cast<Shape>(shape)){
        Atribuition();
    }
    ~Figure(){}
    void Atribuition();
    int Random();

protected:
    Fiches form[4]; 
    Shape shape;
};

#endif
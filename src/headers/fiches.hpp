#ifndef FICHES_CLASS
#define FICHES_CLASS
#include <iostream>
#include "color.hpp"
#include "shape.hpp"

class Fiches
{
public:
        //Constructeurs et Deconstructeurs
    Fiches () {};
    Fiches (Color color, int x, int y) 
        : color(color), posX(x), posY(y) {};
    Fiches (Color color)
        : color(color) {};
    ~Fiches() {};
    

        //Getters de la Classe
    Color getColor(){
        return color;
    }

    int getX(){
        return posX;
    }

    int getY(){
        return posY;
    }


        //Setters de la Classe
    void setPosX(int x){
        posX = x;
    }

    void setPosY(int y){
        posY = y;
    }

    void setColor(Color cor){
        color = cor;
    }


protected:
    Color color;
    int posX = 4;
    int posY = 0;
};
#endif
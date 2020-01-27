#ifndef FIGURE_CLASS 
#define FIGURE_CLASS
#include "./board.hpp"
#include <random>


class Figure{
public:
        //Constructeur
    Figure(){};
    ~Figure(){}
    void newBlock();
    int Random();

public:
    int form[7][4][4] = {
        1,0,0,0,
        1,0,0,0,
        1,0,0,0,
        1,0,0,0,

        1,0,0,0,
        1,1,0,0,
        0,1,0,0,
        0,0,0,0,

        0,1,0,0,
        1,1,0,0,
        1,0,0,0,
        0,0,0,0,

        1,1,0,0,
        1,1,0,0,
        0,0,0,0,
        0,0,0,0,

        1,0,0,0,
        1,1,0,0,
        1,0,0,0,
        0,0,0,0,

        0,1,0,0,
        0,1,0,0,
        1,1,0,0,
        0,0,0,0,

        1,0,0,0,
        1,0,0,0,
        1,1,0,0,
        0,0,0,0,
    };
    int posX = LARGUEUR/2, posY = 0;
    int kind = rand() % 7;
};

#endif
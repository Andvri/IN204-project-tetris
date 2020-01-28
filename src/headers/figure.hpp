#ifndef FIGURE_CLASS 
#define FIGURE_CLASS

#include <iostream>
#include <ctime>    
#include <cstdlib>  

class Figure{
public:
        //Constructeur
    Figure();
    ~Figure(){}
    void newBlock();
    void rotate();
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
    int posX, posY;
    int kind;
};

#endif
#ifndef FIGURE_CLASS 
#define FIGURE_CLASS

#include <iostream>
#include <ctime>    
#include <cstdlib>  

class Figure{
public:
    Figure();
    ~Figure(){};

    void newBlock();
    void rotate();
    int random();
    void atribbuition(int kind);

    int getPontualForm(int y, int x);
    int getPosX();
    int getPosY();
    int getKind();

    int addPosX(int x);
    int addPosY(int y);

private:
    int form[4][4];
    int posX, posY;
    int kind;
};

#endif
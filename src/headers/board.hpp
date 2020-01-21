#ifndef BOARD_CLASS
#define BOARD_CLASS
#include <iostream>


#define LARGUEUR 10
#define HAUTER 20

class Board{
public:
    Board();
    void start();
    bool limitation(int height, int width);
    bool filledLine(int width);


protected:
    int tableau[HAUTER][LARGUEUR]; //0 = not filled; 1 = filled 
    int x = 5, y = 0;

};
#endif

#ifndef BOARD_CLASS
#define BOARD_CLASS
#include <iostream>


#define LARGUEUR 10
#define HAUTER 20

class Board{
public:
    Board();
    void start();


    int tableau[HAUTER][LARGUEUR]; 
};
#endif
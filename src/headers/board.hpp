#ifndef BOARD_CLASS
#define BOARD_CLASS

#include "./figure.hpp"

#define BLOCKSIZE 30
#define LARGUEUR 10
#define HAUTER 20

class Board{
public:
    Board();
    
    void clearLines();
    bool checkLimits(Figure tetrino);
    ~Board(){};


    int tableau[HAUTER][LARGUEUR];

};
#endif

#ifndef BOARD_CLASS
#define BOARD_CLASS
#include <iostream>
#include <SFML/Graphics.hpp>

#define BLOCKSIZE 30
#define LARGUEUR 10
#define HAUTER 20

class Board{
public:
    Board(){};
    ~Board(){};

public:
    int tableau[HAUTER][LARGUEUR] = {0}; //0 = not filled; 1 = filled 

};
#endif

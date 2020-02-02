#ifndef BOARD_CLASS
#define BOARD_CLASS

#include "./figure.hpp"
#include "./player.hpp"

#define BLOCKSIZE 30
#define LARGUEUR 10
#define HAUTER 20

class Board{
public:
    Board();
    ~Board(){};

    void clearLines(Player& player);
    bool checkLimits(Figure tetrino);
    
    int getPontualPoint(int y, int x);
    int setPontualPoint(int y, int x, int value);

    
private:
    int tableau[HAUTER][LARGUEUR];

};
#endif

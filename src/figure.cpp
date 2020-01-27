#include <iostream>
#include "./headers/figure.hpp"

void Figure::newBlock(){
    Figure::kind = rand()%7;
    Figure::posX = LARGUEUR/2;
    Figure::posY = 0;
}

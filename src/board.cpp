#include <iostream>
#include "../libraries.hpp"

void Board::start(){
    for (int i = 0; i < HAUTER; i++){
        for (int j = 0; j < LARGUEUR; j++){
            tableau[i][j] = 0; 
        }
    }
}

bool Board::filledLine(int width){
    int cont = 0;
    for (int i = 0; i < HAUTER; i++){
        for (int j = 0; j < LARGUEUR; j++){
            if (tableau[i][j] == 1){
                cont++;
            }
        }

        if (cont == 10){
            
            cont = 0;
        }else{}{
            cont = 0;
        }
    }       
}


// bool Board::limitation(int height, int width){
//     if ()
// }
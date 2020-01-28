#include "./headers/board.hpp"


inline Board::Board(){
    tableau[LARGUEUR][HAUTER] = {0};
}

inline void Board::clearLines(){
    int top = HAUTER -1;

    for (int from = HAUTER -1; from >= 0; from--){
        int counter = 0;

        for (int x = 0; x < LARGUEUR; x++){
            if (tableau[from][x])
                counter++;
        }
        if (counter < LARGUEUR){
            for (int x = 0; x < LARGUEUR; x++){
                tableau[top][x] = tableau[from][x];
            }
            top--;
        }
    }
};

inline bool Board::checkLimits(Figure tetrino){
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (tetrino.form[tetrino.kind][y][x] == 0) continue;
            if (tetrino.posX + x < 0 || tetrino.posX + x >= LARGUEUR || tetrino.posY + y >= HAUTER) return false;
            if (tableau[tetrino.posY + y][tetrino.posX + x]) return false;
        }
    }
    return true;
};
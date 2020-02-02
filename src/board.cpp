#include "./headers/board.hpp"


inline Board::Board(){
    tableau[LARGUEUR][HAUTER] = {0};
}

inline void Board::clearLines(Player& player){
    int top = HAUTER -1, cntlines = 0;

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
        if (counter == LARGUEUR) cntlines++;
    }
    player.updateScore(cntlines);
};

inline bool Board::checkLimits(Figure tetrino){
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (tetrino.getPontualForm(y, x) == 0) continue;
            if (tetrino.getPosX() + x < 0 || tetrino.getPosX() + x >= LARGUEUR || tetrino.getPosY() + y >= HAUTER) return false;
            if (tableau[tetrino.getPosY() + y][tetrino.getPosX() + x]) return false;
        }
    }
    return true;
};



inline int Board::getPontualPoint(int y, int x){
    return tableau[y][x];
};

inline int Board::setPontualPoint(int y, int x, int value){
    tableau[y][x] = value;
};
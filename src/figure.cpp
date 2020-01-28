#include "./headers/figure.hpp"
#include "./headers/board.hpp"

inline int Figure::Random(){
    srand(time(0));  
    return (rand() % 6);
}


inline Figure::Figure(){
    posX = LARGUEUR/2;
    posY = 0;
    kind = Random();
}


inline void Figure::newBlock(){
    kind = rand()%7;
    posX = 10/2;
    posY = 0;
}

inline void Figure::rotate(){
    int len = 0;
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (form[kind][y][x]){
                len = std::max(std::max(x, y) + 1, len);
            }
        }
    }
    int d[4][4] = {0};
        //rotation en 90degrees
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (form[kind][y][x]){
                d[len -1 -x][y] = 1;
            }
        }
    }
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            form[kind][y][x] = d[y][x];
        }
    }
};
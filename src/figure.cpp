#include "./headers/figure.hpp"
#include "./headers/board.hpp"

inline int Figure::random(){
    srand(time(0));  
    return (rand() % 7);
}

inline void Figure::atribbuition(int kind){
    switch (kind){
    case 0: //I
        form[0][0] = 1;
        form[1][0] = 1;
        form[2][0] = 1;
        form[3][0] = 1;
        break;
    case 1: //S
        form[0][0] = 1;
        form[1][0] = 1;
        form[1][1] = 1;
        form[2][1] = 1;
        break;
    case 2: //Z
        form[0][1] = 1;
        form[1][1] = 1;
        form[1][0] = 1;
        form[2][0] = 1;
        break;
    case 3: //O
        form[0][0] = 1;
        form[1][1] = 1;
        form[0][1] = 1;
        form[1][0] = 1;
        break;
    case 4: //T
        form[0][0] = 1;
        form[1][0] = 1;
        form[1][1] = 1;
        form[2][0] = 1;
        break;
    case 5: //J
        form[0][1] = 1;
        form[1][1] = 1;
        form[2][1] = 1;
        form[2][0] = 1;
        break;
    case 6: //L
        form[0][0] = 1;
        form[1][0] = 1;
        form[2][0] = 1;
        form[2][1] = 1;
        break;
    default:
        int forms[4][4] = {0};
        break;
    }

}


inline Figure::Figure(){
    for(int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++)
            form[y][x] = 0;
    }
    posX = LARGUEUR/2;
    posY = 0;
    kind = random();
    atribbuition(kind);
}


inline void Figure::newBlock(){
    for(int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++)
            form[y][x] = 0;
    }
    kind = random();
    atribbuition(kind);
    posX = LARGUEUR/2;
    posY = 0;
}

inline void Figure::rotate(){
    int len = 0, check = 0;
    int  cont[4] = {0};

    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (form[y][x]){
                len = std::max(std::max(x, y) + 1, len);
            }
        }
    }
    int d[4][4] = {0};
        //rotation en 90degrees
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            if (form[y][x]){
                d[len -1 -x][y] = 1;
                if (y != 0) cont[y]++;
            }
        }
    }

    for (int i = 0; i < 4; i++){
        check = std::max(cont[i], check);
    }

    if (posX + check > LARGUEUR-1) posX-=check;


    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            form[y][x] = d[y][x];
        }
    }
};

    //Getters
inline int Figure::getPontualForm(int y, int x){
    return form[y][x];
}
inline int Figure::getPosX(){
    return posX;
}
inline int Figure::getPosY(){
    return posY;
}
inline int Figure::getKind(){
    return kind;
}

    //Setters
inline int Figure::addPosX(int x){
    posX += x;
}

inline int Figure::addPosY(int y){
    posY += y;
}
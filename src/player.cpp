#include "./headers/player.hpp"
#include <iostream>

inline Player::Player(){
    score = 0;
    lines = 0;
    level = 0;
    levelUp = false;
};

inline int Player::getScore(){
    return score;
};
inline int Player::getLines(){
    return lines;
};
inline int Player::getLevel(){
    return level;
};

inline void Player::updateScore(int checkLines){
    if (checkLines == 1){
        score = score + 40;
        std::cout << "Nova Pontuaçao:" << score << "\n";
        updateLines(checkLines);
        std::cout << "Lines: " << lines << "\n";
    }else if (checkLines == 2){
        score += 100;
        std::cout << "Nova Pontuaçao:" << score << "\n";
        updateLines(checkLines);
        std::cout << "Lines: " << lines << "\n";
    }else if (checkLines == 3){
        score += 300;
        std::cout << "Nova Pontuaçao:" << score << "\n";
        updateLines(checkLines);
        std::cout << "Lines: " << lines << "\n";
    }else if (checkLines  == 4){
        score += 1200;
        std::cout << "Nova Pontuaçao:" << score << "\n";
        updateLines(checkLines);
        std::cout << "Lines: " << lines << "\n";
    }else if (checkLines > 4){
        score += 1200;
        std::cout << "Nova Pontuaçao:" << score << "\n";
        updateLines(4);
        std::cout << "Lines: " << lines << "\n";
        checkLines %= 4;
        updateScore(checkLines);
    }
};

inline void Player::updateLines(int countLines){
    lines += countLines;
    updateLevel(lines);
};

inline void Player::updateLevel(int countLevel){
    int aux = level;
    level = countLevel / 10;
    if (level != aux)   levelUp = true;
};


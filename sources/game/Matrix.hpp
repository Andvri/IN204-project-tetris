#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <SFML/Graphics.hpp>
#include <vector>
#include "AvailableColors.hpp"
#include <iostream>


#ifndef CLASS_TETROMINO
#define CLASS_TETROMINO
class Tetromino;
#endif


class Matrix
{
private:
    bool tetrominoCompatible(std::vector<sf::Vector2i> pos);
    int mHeight;
    int mWidth;
    std::vector<int> mPos;

 
public:
    int codePosition(int x, int y);
    sf::Vector2i decodePosition(int code);

    int getWidth();
    int getHeight();

    Matrix();
    Matrix(const Matrix& m);
    Matrix(int width, int height);
    ~Matrix();
    bool    operator ==( Tetromino &t);
    friend Matrix& operator +(Matrix &m,Tetromino &t);
    friend std::ostream& operator << (std::ostream &o,Matrix &m);
};



#endif
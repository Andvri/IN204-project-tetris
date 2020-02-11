#include "Matrix.hpp"
#include "Tetromino.hpp"
Matrix::Matrix(/* args */):
    mHeight(20),
    mWidth(10)
{
}

Matrix::Matrix(int width, int height):
    mHeight(height),
    mWidth(width),
    mPos(width*height, AvailableColors::TRANSPARENT)
{
}

Matrix::~Matrix()
{
}


bool Matrix::operator==( Tetromino &t)
{
    return this->tetrominoCompatible(t.getPos());
}


bool Matrix::tetrominoCompatible(std::vector<sf::Vector2i> pos)
{
    for (auto p : pos)
    {
        if (mPos[codePosition(p.x,p.y)] != AvailableColors::TRANSPARENT) return false;
    }
    
    return true;
}


int Matrix::getWidth()
{
    return mWidth;
}
int Matrix::getHeight()
{
    return mHeight;
}

int Matrix::codePosition(int x, int y)
{
    return (mWidth*y) + x;
}
sf::Vector2i Matrix::decodePosition(int code)
{
    int y = code / mWidth;
    int x = code - (y*mWidth);
    return sf::Vector2i(x,y);
}
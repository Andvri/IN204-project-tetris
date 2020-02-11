#include "Tetromino.hpp"
#include "Matrix.hpp"
#include <iostream>
#include "../utils/ExceptionType.hpp"

Tetromino::Tetromino(int mBorderX, int mBorderY, AvailableColors mColor): 
    mPos(),
    mColor(mColor),
    mBorderX(mBorderX),
    mBorderY(mBorderY)
{
    for (size_t i = 0; i < 4; i++)
    {
        mPos.push_back(sf::Vector2i(i, (i+1)*2) );
    }
    mPos[0] = sf::Vector2i(0, 4);
    mPos[1] = sf::Vector2i(1, 2);
    
}

Tetromino::Tetromino(AvailableColors mColor): 
    mPos(),
    mColor(mColor),
    mBorderX(0),
    mBorderY(0)
{
    for (size_t i = 0; i < 4; i++)
    {
        mPos.push_back(sf::Vector2i(i, (i+1)*2) );
    }
    
}

Tetromino::~Tetromino()
{}

Tetromino::Tetromino(const Tetromino &t)
{
    this->mBorderX = t.mBorderX;
    this->mBorderY = t.mBorderY;
    this->mPos = t.mPos;
    this->mColor = t.mColor;
}

void Tetromino::print()
{
    for (sf::Vector2i p : mPos)
    {
        std::cout << "(" << p.x << "," << p.y  << ")" << std::endl;
    }
    
    std::cout << std::endl;
}

Tetromino& Tetromino::operator++ (int) 
{
    Tetromino copy = Tetromino(*this);
    for (sf::Vector2i &p : mPos)
    {
        try
        {
            p.y++;
            if (p.y < 0 || p.y >= this->mBorderY) 
                throw TETROMINO_OUT_OF_LIMITS;
        }
        catch(ExceptionType outLimits)
        {
            *this = copy;
            break;
        }
    }
    return *this;
}

Tetromino& Tetromino::operator-- (int) 
{
    Tetromino copy = Tetromino(*this);
    for (sf::Vector2i &p : mPos)
    {
        try
        {
            p.y--;
            if (p.y < 0 || p.y >= this->mBorderY) 
                throw TETROMINO_OUT_OF_LIMITS;
        }
        catch(ExceptionType outLimits)
        {
            *this = copy;
            break;
        }
    }
    return *this;
}

Tetromino& operator+(const Tetromino &t1, const int offsetX)
{
    Tetromino* n = new Tetromino(t1);
    for (auto &&i : n->mPos)
    {
        try
        {
            i.x += offsetX;
            if (i.x < 0 || i.x >= t1.mBorderX) 
                throw TETROMINO_OUT_OF_LIMITS;
        }
        catch(ExceptionType outLimits)
        {
            n = new Tetromino(t1);
            break;
        }
        
    }
    

    return *n;
}

Tetromino& operator-(const Tetromino &t1, const int offsetX)
{
    
    Tetromino* n = new Tetromino(t1);
    for (auto &&i : n->mPos)
    {
        try
        {
            i.x -= offsetX;
            if (i.x < 0 || i.x >= t1.mBorderX) 
                throw TETROMINO_OUT_OF_LIMITS;
        }
        catch(ExceptionType outLimits)
        {
            n = new Tetromino(t1);
            break;
        }
    }
    
    return *n;
}

AvailableColors Tetromino::getColor()
{
    return mColor;
}

std::vector<sf::Vector2i> Tetromino::getPos()
{
    return mPos;
}


bool Tetromino::operator==( Matrix &m)
{
    return m == *this;
}

void Tetromino::rotate(Direction d)
{
    std::cout << d << std::endl;
}

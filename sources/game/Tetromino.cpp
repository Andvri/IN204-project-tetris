#include "Tetromino.hpp"
#include "Matrix.hpp"
#include <iostream>

Tetromino::Tetromino(AvailableColors mColor): 
    mPos(),
    mColor(mColor)

{
    for (size_t i = 0; i < 4; i++)
    {
        mPos.push_back(sf::Vector2i(i, (i+1)*2) );
    }
    
}

Tetromino::~Tetromino()
{}

void Tetromino::print()
{
    for (sf::Vector2i p : mPos)
    {
        std::cout << "(" << p.x << "," << p.y  << ")" << std::endl;
    }
    
}

Tetromino& Tetromino::operator++ (int) 
{
    for (sf::Vector2i &p : mPos)
    {
        p.y++;
    }
    return *this;
}

Tetromino& Tetromino::operator-- (int) 
{
    for (sf::Vector2i &p : mPos)
    {
        p.y--;
    }
    return *this;
}

Tetromino& operator+(const Tetromino &t1, const int offsetX)
{
    Tetromino* n = new Tetromino();
    for (auto &&i : n->mPos)
    {
        i.x += offsetX;
    }
    

    return *n;
}

Tetromino& operator-(const Tetromino &t1, const int offsetX)
{
    Tetromino* n = new Tetromino();
    for (auto &&i : n->mPos)
    {
        i.x -= offsetX;
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

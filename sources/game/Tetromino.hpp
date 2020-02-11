#ifndef TETROMINO_CLASS
#define TETROMINO_CLASS

#include "AvailableColors.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Direction.hpp"

#ifndef CLASS_MATRIX
#define CLASS_MATRIX
class Matrix;
#endif

class Tetromino
{
private:    
    std::vector<sf::Vector2i> mPos;
    AvailableColors mColor;
public:
    Tetromino(AvailableColors mColor = AvailableColors::TRANSPARENT);
    virtual				~Tetromino();
    virtual void rotate(Direction d = Direction::CLOCKWISE);
    void print();
    void setPos(std::vector<sf::Vector2i> pos);

    AvailableColors getColor();
    std::vector<sf::Vector2i> getPos();


    Tetromino& operator ++(int);
    Tetromino& operator --(int);

    bool    operator ==( Matrix &m);
    friend Tetromino& operator +(const Tetromino &t1,const int offsetX);

    friend Tetromino& operator -(const Tetromino &t1,const int offsetX);

}; 


#endif
#ifndef Z_CLASS
#define Z_CLASS
#include "Tetromino.hpp"
#include <iostream>
class Z
    : public  Tetromino
{
private:
    /* data */
public:
    Z(/* args */);
    ~Z();
    virtual void rotate(Direction d = Direction::CLOCKWISE);
};

Z::Z(/* args */)
    : Tetromino()
{
}

Z::~Z()
{
}

void Z::rotate(Direction d)
{
}

#endif
#ifndef TETROMINO_CLASS
#define TETROMINO_CLASS

#include "AvailableColors.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>

#include "CollisionDirection.hpp"
#include "Direction.hpp"

#ifndef CLASS_MATRIX
#define CLASS_MATRIX
class Matrix;
#endif

class Tetromino
{

public:
    typedef std::function<void(CollisionDirection cd)>		Callback;
private:    
    std::vector<sf::Vector2i> mPos;
    int mBorderX;
    int mBorderY;

    Callback		mOnCollisionEvent;
    AvailableColors mColor;
    void callCollisionEvent(CollisionDirection cd);
public:
    Tetromino(int mBorderX, int mBorderY, AvailableColors mColor = AvailableColors::TRANSPARENT);
    Tetromino(AvailableColors mColor = AvailableColors::TRANSPARENT);
    Tetromino(const Tetromino &t);

    virtual				~Tetromino();
    virtual void rotate(Direction d = Direction::CLOCKWISE);
    void print();
    void setPos(std::vector<sf::Vector2i> pos);

    AvailableColors getColor();
    std::vector<sf::Vector2i> getPos();
    
    void setCollisionEvent(Callback callback);

    Tetromino& operator ++(int);
    Tetromino& operator --(int);

    bool    operator ==( Matrix &m);
    friend Tetromino& operator +(const Tetromino &t1,const int offsetX);

    friend Tetromino& operator -(const Tetromino &t1,const int offsetX);

}; 


#endif
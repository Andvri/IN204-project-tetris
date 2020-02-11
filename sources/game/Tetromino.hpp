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

    int structuralAxis = 2;
    int offsetX = 1;
    std::vector<sf::Vector2i> mFigureStructure = {
        sf::Vector2i(0,-2),
        sf::Vector2i(0,-1),
        sf::Vector2i(0,0),
        sf::Vector2i(-1,0)
    };
    void callCollisionEvent(CollisionDirection cd);
public:
    Tetromino(int mBorderX, int mBorderY, AvailableColors mColor);
    Tetromino(int mBorderX, int mBorderY);
    Tetromino(AvailableColors mColor = AvailableColors::TRANSPARENT);
    Tetromino(const Tetromino &t);

    virtual				~Tetromino();
    virtual void rotate(Direction d = Direction::CLOCKWISE);

    // TODO: Overloading the corresponding operator std::ostream << 
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
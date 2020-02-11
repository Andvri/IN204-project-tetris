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
    int lowestPosition(bool axisY = true);
private:    
    std::vector<sf::Vector2i> mPos;
    int mBorderX;
    int mBorderY;

    Callback		mOnCollisionEvent;
    AvailableColors mColor;

    int structuralAxis = 2;
    int offsetX = 1;
    std::vector<sf::Vector2i> mFigureStructure = {
        sf::Vector2i(0,0),
        sf::Vector2i(0,1),
        sf::Vector2i(0,-1),
        sf::Vector2i(-1,0)
    };
    void callCollisionEvent(CollisionDirection cd);
    bool callEvent = true;

public:
    Tetromino(int mBorderX, int mBorderY, AvailableColors mColor);
    Tetromino(int mBorderX, int mBorderY);
    Tetromino(AvailableColors mColor = AvailableColors::TRANSPARENT);
    Tetromino(const Tetromino &t);
    Tetromino(int mBorderX, int mBorderY, int offsetX, int offsetY, std::vector<sf::Vector2i> figureStructure, AvailableColors mColor);

    virtual				~Tetromino();
    virtual void rotate(Direction d = Direction::CLOCKWISE);

    // TODO: Overloading the corresponding operator std::ostream << 
    void print();

    bool offsetAxis(bool axixY = true);
    void setPos(std::vector<sf::Vector2i> pos);

    AvailableColors getColor();
    std::vector<sf::Vector2i> getPos();
    
    void setCollisionEvent(Callback callback);

    Tetromino& operator ++(int);
    Tetromino& operator --(int);

    bool    operator ==( Matrix &m);
    bool    operator ==( Tetromino &t);
    friend Tetromino& operator +(const Tetromino &t1,const int offsetX);

    friend Tetromino& operator -(const Tetromino &t1,const int offsetX);

    void disableEvent();
    void enableEvent();

    std::vector<sf::Vector2i> rotateFigureStructure(Direction d = Direction::CLOCKWISE);

    sf::Vector2i getAxisCoordinates();
    int getBorderX();
    int getBorderY();

    Tetromino cloneAndRotate(Direction d = Direction::CLOCKWISE);
    void correctBorder();
}; 


#endif
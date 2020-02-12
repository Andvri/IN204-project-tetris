#include "Tetromino.hpp"
#include "Matrix.hpp"
#include <iostream>
#include<cstdlib>
#include "../utils/ExceptionType.hpp"

const std::vector<std::vector<sf::Vector2i>> Tetromino::figuresAvalibles = {
        // T
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(-1,0),
            sf::Vector2i(0,-1)
        },
        // Z
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(0,-1),
            sf::Vector2i(-1,-1)
        },
        // S
        {
            sf::Vector2i(0,0),
            sf::Vector2i(-1,0),
            sf::Vector2i(1,-1),
            sf::Vector2i(0,-1)
        },
        // I
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(-1,0),
            sf::Vector2i(-2,0)
        },
        // O
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(1,-1),
            sf::Vector2i(0,-1)
        },
        // L
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(-1,-1),
            sf::Vector2i(-1,0)
        },
        // J
        {
            sf::Vector2i(0,0),
            sf::Vector2i(1,0),
            sf::Vector2i(1,-1),
            sf::Vector2i(-1,0)
        },
        // .
        {
            sf::Vector2i(0,0),
        },
        // M
        {
            sf::Vector2i(0,0),
            sf::Vector2i(2,0),
            sf::Vector2i(-2,0),
            sf::Vector2i(-1,-1),
            sf::Vector2i(1,-1),
        }
};



Tetromino::Tetromino(int mBorderX, int mBorderY, AvailableColors mColor): 
    mPos(),
    mColor(mColor),
    mBorderX(mBorderX),
    mBorderY(mBorderY)
{
    int axisY = -1*offsetX;
    int axisX = (mBorderX/2);


    for (auto pixel : mFigureStructure)
    {
        mPos.push_back(sf::Vector2i(axisX+pixel.x, axisY+pixel.y));
    }
    
}

Tetromino::Tetromino(int mBorderX, int mBorderY, int offsetX, int offsetY, std::vector<sf::Vector2i> figureStructure, AvailableColors mColor):
    mPos(),
    mColor(mColor),
    mBorderX(mBorderX),
    mBorderY(mBorderY),
    mFigureStructure(figureStructure)
{

    /**
     * TODO: Validate the distances between the size 
     * 
     * add cassert
     * 
     */
    for (auto pixel : mFigureStructure)
    {
        mPos.push_back(sf::Vector2i(offsetX+pixel.x, offsetY+pixel.y));
    }
}



Tetromino::Tetromino(int mBorderX, int mBorderY): 
    mPos(),
    mColor(TRANSPARENT),
    mBorderX(mBorderX),
    mBorderY(mBorderY),
    mFigureStructure()
{
    
    int structIndex = (rand()%(Tetromino::figuresAvalibles.size()-1));
    mFigureStructure = figuresAvalibles[structIndex];

    mColor = static_cast<AvailableColors>(structIndex%TRANSPARENT);
    sf::Vector2i axis = mFigureStructure[0];
    int axisY = -1*offsetX;
    int axisX = (mBorderX/2);


    for (auto pixel : mFigureStructure)
    {
        mPos.push_back(sf::Vector2i(axisX+pixel.x, axisY+pixel.y));
    }
    
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
    this->mFigureStructure = t.mFigureStructure;
    if (t.mOnCollisionEvent) this->setCollisionEvent(t.mOnCollisionEvent);
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
            if (p.y >= this->mBorderY) 
                throw TETROMINO_OUT_OF_LIMITS;
        }
        catch(ExceptionType outLimits)
        {

            this->callCollisionEvent((p.y < 0) ? NORTH : SOUTH);
            
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
            if (p.y >= this->mBorderY) 
                throw TETROMINO_OUT_OF_LIMITS;
        }
        catch(ExceptionType outLimits)
        {
            copy.callCollisionEvent((p.y < 0) ? NORTH : SOUTH);
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
            n->callCollisionEvent((i.x < 0) ? WEST : EAST);
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
            n->callCollisionEvent((i.x < 0) ? WEST : EAST);
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


void Tetromino::callCollisionEvent(CollisionDirection cd)
{
    if (mOnCollisionEvent && callEvent) mOnCollisionEvent(cd);
}

void Tetromino::setCollisionEvent(Callback callback)
{
    mOnCollisionEvent = std::move(callback);
}

int Tetromino::lowestPosition(bool axisY)
{
    int pos = -999999;
    for (auto &&i : mPos)
    {
        if (axisY && i.y > pos) pos = i.y;
        else if (!axisY && i.x > pos) pos = i.x;
    }
    return pos;
}

bool Tetromino::offsetAxis(bool axisY)
{
    for (auto &&i : mPos)
    {
        if (axisY && i.y < 0) return false;
        else if (!axisY && i.x < 0) return false;
    }
    return true;
}

void Tetromino::disableEvent()
{
    callEvent = false;
}

void Tetromino::enableEvent()
{
    callEvent = true;
}

std::vector<sf::Vector2i> Tetromino::rotateFigureStructure(Direction d)
{
    int coefX = (d == Direction::CLOCKWISE) ? -1 : 1;
    int coefY = (d == Direction::CLOCKWISE) ? 1 : -1;
    std::vector<sf::Vector2i> copy(getStucture());

    for (auto &i : copy)
    {
        int oldX = i.x;
        int oldY = i.y;

        i.x = oldY * coefX;
        i.y = oldX * coefY;
    }
    
    return copy;
}

sf::Vector2i Tetromino::getAxisCoordinates()
{
    return sf::Vector2i(mPos[0]);
}
int Tetromino::getBorderX()
{
    return mBorderX;
}
int Tetromino::getBorderY()
{
    return mBorderY;
}

Tetromino Tetromino::cloneAndRotate(Direction d)
{
    Tetromino t(
        this->getBorderX(), 
        this->getBorderY(),
        this->getAxisCoordinates().x, 
        this->getAxisCoordinates().y, 
        this->rotateFigureStructure(d),
        this->getColor()
    );
    return t;
}

void Tetromino::correctBorder()
{
    this->disableEvent();
    int lMaxWidht = this->getBorderX()-1;
    int lMaxHeight = this->getBorderY()-1;
    int lMinimumWidht = 0;
    for (auto &&i : this->getPos())
    {
        if (i.x > lMaxWidht) {
            lMaxWidht++;
        }
    }

    lMaxWidht -=(this->getBorderX()-1); 

    for (size_t i = 0; i < lMaxWidht; i++)
    {
        (*this) = (*this) - 1;
    }
    

    for (auto &&i : this->getPos())
    {
        if (i.x < lMinimumWidht) {
            lMinimumWidht--;
        }
    }

    lMinimumWidht *= (-1); 

    for (size_t i = 0; i < lMinimumWidht; i++)
    {
        (*this) = (*this) + 1;
    }

    for (auto &&i : this->getPos())
    {
        if (i.y > lMaxHeight) {
            lMaxHeight++;
        }
    }

    lMaxHeight -=(this->getBorderY()-1); 

    for (size_t i = 0; i < lMaxHeight; i++)
    {
        (*this)--;
    }
    this->enableEvent();
    
}


bool Tetromino::operator==( Tetromino &t)
{

    for (size_t i = 0; i < t.getPos().size(); i++)
    {
        if (this->getPos()[i] != t.getPos()[i]) return false;
    }
    

    return true;
}

const std::vector<sf::Vector2i> Tetromino::getStucture()
{
    return mFigureStructure;
}
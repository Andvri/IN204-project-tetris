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

    /**
     * @brief Look for the smallest position between the X and Y values of the part in question
     * 
     * @param axisY 
     * @return int value of lowest position between x and y
     */
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

    const static std::vector<std::vector<sf::Vector2i>> figuresAvalibles;

    /**
     * @brief Checks if the collision between the tetromino and the direction it seeks (north, south, east and west)
     * 
     * @param cd directions
     */
    void callCollisionEvent(CollisionDirection cd);
    bool callEvent = true;

public:
    /**
     * @brief Get the Stucture object current
     * 
     * @return const std::vector<sf::Vector2i> with positions in content 
     */
    const std::vector<sf::Vector2i> getStucture();
    Tetromino(int mBorderX, int mBorderY, AvailableColors mColor);
    Tetromino(int mBorderX, int mBorderY);
    Tetromino(AvailableColors mColor = AvailableColors::TRANSPARENT);
    Tetromino(const Tetromino &t);
    Tetromino(int mBorderX, int mBorderY, int offsetX, int offsetY, std::vector<sf::Vector2i> figureStructure, AvailableColors mColor);

    virtual				~Tetromino();

    /**
     * @brief uses the rotation function (x,y) = (y, -x)
     * 
     * @param d orientation: Clokwise or anti-clockwise
     */
    virtual void rotate(Direction d = Direction::CLOCKWISE);

    // TODO: Overloading the corresponding operator std::ostream << 
    void print();

    bool offsetAxis(bool axixY = true);
    void setPos(std::vector<sf::Vector2i> pos);

    /**
     * @brief Get the Color object
     * 
     * @return the color of piece 
     */
    AvailableColors getColor();

    /**
     * @brief Get the Pos of tetromino in table
     * 
     * @return (x;y)
     */
    std::vector<sf::Vector2i> getPos();
    
    /**
     * @brief Set the Collision Event to treat him and call the collision function
     * 
     * @param callback 
     */
    void setCollisionEvent(Callback callback);

    /**
     * @brief vertical movement of the tetromino
     * 
     * @return Tetromino& 
     */
    Tetromino& operator ++(int);

    /**
     * @brief vertical movement of the tetromino
     * 
     * @return Tetromino& 
     */
    Tetromino& operator --(int);

    /**
     * @brief Insert value in the matrix directly just checking whether or not the space is available
     * 
     * @param m 
     * @return true 
     * @return false 
     */
    bool    operator ==( Matrix &m);

    /**
     * @brief Comparation between tetrominos
     * 
     * @param t 
     * @return true 
     * @return false 
     */
    bool    operator ==( Tetromino &t);

    /**
     * @brief Make the movement in x, making the horizontal movement of the piece in which we move in the positive direction
     * 
     * @param t1 
     * @param offsetX 
     * @return Tetromino& 
     */
    friend Tetromino& operator +(const Tetromino &t1,const int offsetX);

    /**
     * @brief Make the movement in x, making the horizontal movement of the piece in which we move in the negative direction
     * 
     * @param t1 
     * @param offsetX 
     * @return Tetromino& 
     */
    friend Tetromino& operator -(const Tetromino &t1,const int offsetX);

    void disableEvent();
    void enableEvent();

    /**
     * @brief If it is possible to rotate the part according to the checking function, it is responsible for actually rotating the piece in real positions and fix it
     * 
     * @param d 
     * @return std::vector<sf::Vector2i> 
     */
    std::vector<sf::Vector2i> rotateFigureStructure(Direction d = Direction::CLOCKWISE);

    /**
     * @brief Get the Axis Coordinates object
     * 
     * @return sf::Vector2i in (x,y)
     */
    sf::Vector2i getAxisCoordinates();

    /**
     * @brief Get the Border X object
     * 
     * @return int 
     */
    int getBorderX();

    /**
     * @brief Get the Border Y object
     * 
     * @return int 
     */
    int getBorderY();


    /**
     * @brief Clone the part before rotating it, if the clone can be fitted into the matrix, it will assume the original position, thus making the rotation movement
     * 
     * @param d 
     * @return Tetromino 
     */
    Tetromino cloneAndRotate(Direction d = Direction::CLOCKWISE);

    /**
     * @brief Check if there is a conflict between the edges of the matrix, and if there is, make the right correction so as not to blast the boundaries
     * 
     */
    void correctBorder();
}; 


#endif
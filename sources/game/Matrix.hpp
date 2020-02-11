#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <SFML/Graphics.hpp>
#include <vector>
#include "AvailableColors.hpp"

#ifndef CLASS_TETROMINO
#define CLASS_TETROMINO
class Tetromino;
#endif


class Matrix
{
public:
    typedef std::function<void()>		Callback;
private:
    Callback		mOnCollisionEvent;
    bool tetrominoCompatible(std::vector<sf::Vector2i> pos);
    int mHeight;
    int mWidth;
    std::vector<int> mPos;

    void callCollisionEvent();

public:
    int codePosition(int x, int y);
    sf::Vector2i decodePosition(int code);

    int getWidth();
    int getHeight();

    void setCollisionEvent(Callback callback);
    Matrix();
    Matrix(int width, int height);
    ~Matrix();
    bool    operator ==( Tetromino &t);
};



#endif
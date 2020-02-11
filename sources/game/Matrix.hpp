#ifndef MATRIX_CLASS
#define MATRIX_CLASS
#include "AvailableColors.hpp"
#ifndef CLASS_TETROMINO
#define CLASS_TETROMINO
class Tetromino;
#endif


class Matrix
{
private:
    bool egalTetromino(AvailableColors c);
public:
    Matrix(/* args */);
    ~Matrix();
    bool    operator ==( Tetromino &t);
};



#endif
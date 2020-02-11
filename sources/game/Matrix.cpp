#include "Matrix.hpp"
#include "Tetromino.hpp"
Matrix::Matrix(/* args */)
{
}

Matrix::~Matrix()
{
}


bool Matrix::operator==( Tetromino &t)
{
    return this->egalTetromino(t.getColor());
}


bool Matrix::egalTetromino(AvailableColors c)
{
    return c == AvailableColors::BLUE;
}
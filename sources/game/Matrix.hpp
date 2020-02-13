#ifndef MATRIX_CLASS
#define MATRIX_CLASS

#include <SFML/Graphics.hpp>
#include <vector>
#include "AvailableColors.hpp"
#include <iostream>


#ifndef CLASS_TETROMINO
#define CLASS_TETROMINO
class Tetromino;
#endif


class Matrix
{
private:
    int mHeight;
    int mWidth;
    std::vector<int> mPos;

 
public:
    /**
     * @brief Check all the board positions according to the next positions to check if it is possible to fit the piece
     * 
     * @param pos 
     * @return true 
     * @return false if it is not possible to fit the piece
     */
    bool tetrominoCompatible(std::vector<sf::Vector2i> pos);

    /**
     * @brief Encodes received coordinates; from 2D to 1D
     * 
     * @param x Position value
     * @param y Position value
     * @return The coding
     */
    int codePosition(int x, int y);

    /**
     * @brief Retrieves the coded message from one dimension to two dimensions
     * 
     * @param code in 1D
     * @return sf::Vector2i with 2D
     */
    sf::Vector2i decodePosition(int code);

    /**
     * @brief Get the Width object
     * 
     * @return int value
     */
    int getWidth();

    /**
     * @brief Get the Height object
     * 
     * @return int value 
     */
    int getHeight();

    /**
     * @brief Get the Pos object in relation to the two coordinates of the matrix
     * 
     * @return std::vector<int> 
     */
    std::vector<int> getPos() const;

    Matrix();
    Matrix(const Matrix& m);
    Matrix(int width, int height);
    ~Matrix();
    /**
     * @brief It directly compares a tetromino with the place where it will be to place it
     * 
     * @param t Tetromino getted for comparation
     * @return true 
     * @return false 
     */
    bool    operator ==( Tetromino &t);

    /**
     * @brief Moves the part in the axis and making the movement of the tetromino simpler
     * 
     * @param m Base Matrix
     * @param t tetromino for comparation
     * @return Matrix& 
     */
    friend Matrix& operator +(Matrix m,Tetromino &t);
    friend std::ostream& operator << (std::ostream &o,Matrix &m);

    /**
     * @brief Checks the lines to update according to the parts that are already positioned inside the matrix
     * 
     * @param t positions of tetromino
     * @return int 
     */
    int updateLines(Tetromino t);

    /**
     * @brief Reset Matrix
     * 
     */
    void restart();
};



#endif
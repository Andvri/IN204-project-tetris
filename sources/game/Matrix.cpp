#include "Matrix.hpp"
#include "Tetromino.hpp"
Matrix::Matrix(/* args */):
    mHeight(20),
    mWidth(10)
{
}

Matrix::Matrix(int width, int height):
    mHeight(height),
    mWidth(width),
    mPos(width*height, AvailableColors::TRANSPARENT)
{
}

Matrix::Matrix(const Matrix& m)
{
    this->mHeight = m.mHeight;
    this->mWidth = m.mWidth;
    this->mPos = m.mPos;
}

Matrix::~Matrix()
{
}


bool Matrix::operator==( Tetromino &t)
{
    return this->tetrominoCompatible(t.getPos());
}


bool Matrix::tetrominoCompatible(std::vector<sf::Vector2i> pos)
{
    
    for (auto p : pos)
    {
        if(p.y>=0)
            if (mPos[codePosition(p.x,p.y)] != AvailableColors::TRANSPARENT  ) 
                return false;
    }
    
    return true;
}


int Matrix::getWidth()
{
    return mWidth;
}
int Matrix::getHeight()
{
    return mHeight;
}

int Matrix::codePosition(int x, int y)
{
    return (mWidth*y) + x;
}
sf::Vector2i Matrix::decodePosition(int code)
{
    int y = code / mWidth;
    int x = code - (y*mWidth);
    return sf::Vector2i(x,y);
}

Matrix& operator+(Matrix &m,Tetromino &t)
{
    Matrix *copy = new Matrix(m);
    std::vector<sf::Vector2i> pos(t.getPos());

    for (auto &&p : pos){
        if(p.y>=0)
        {
            copy->mPos[m.codePosition(p.x,p.y)] = t.getColor();
        }
    }
            
    return *copy;
}


std::ostream& operator << (std::ostream &o, Matrix &m)
{
    for (size_t i = 0; i < m.mHeight; i++)
    {
        for (size_t j = 0; j < m.mWidth; j++)
        {
            o << m.mPos[m.codePosition(j,i)];
        }
        o << std::endl;
        
    }
    
    return o;
}

std::vector<int> Matrix::getPos() const
{
    return mPos;
}

void Matrix::updateLines (Tetromino t)
{
    std::vector<int> linesToReview;
    std::vector<sf::Vector2i> pos(t.getPos());
    for (auto &&p : pos){
        if(p.y>=0)
        {
            if (std::find(linesToReview.begin(), linesToReview.end(), p.y) == linesToReview.end()) {
                linesToReview.push_back(p.y);
            }
        }
    }

    std::sort(linesToReview.begin(), linesToReview.end()); 
    for (auto &&line : linesToReview)
    {
        bool check = true;

        for (int k = 0; k < this->getWidth(); k++)
        {
            if (this->mPos[this->codePosition(k,line)] ==  TRANSPARENT) {
                check = false;
                break;
                
            }
        }
        

        if (check) {
            for (size_t i = line; i >0; i--)
            {
                for (size_t j = 0; j < this->getWidth(); j++)
                {
                    if (i == 0) {
                        this->mPos[this->codePosition(j,i)] = TRANSPARENT;
                    } else {
                        this->mPos[this->codePosition(j,i)] = this->mPos[this->codePosition(j,i-1)];
                    }
                }
                
            }
        }
        
        
    }
}
#ifndef SQUARE_CLASS
#define SQUARE_CLASS
#include "../../utils/gui/headers/entity.hpp"
#include "SFML/Graphics.hpp"
class Square:
    public Entity
{
private:
    sf::Color color;
    sf::RectangleShape figure;
public:
    Square(/* args */);
    sf::RectangleShape getFigure() const ;
    
    ~Square();
};

#endif
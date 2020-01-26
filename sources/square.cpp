#include "./headers/square.hpp"

Square::Square(/* args */)
    :
    Entity(),
    color(sf::Color::Red),
    figure()
{
    this->figure.setFillColor(color);
    this->figure.setSize(sf::Vector2f(40,40));
    this->figure.setPosition(100,100);
}

Square::~Square()
{
}

sf::RectangleShape Square::getFigure() const {
    return this->figure;
}

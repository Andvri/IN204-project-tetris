#ifndef GRID_CLASS
#define GRID_CLASS
#include "SFML/Graphics.hpp"
#include <vector>

class Grid
{
private:
    unsigned int height;
    unsigned int width;
    float scale;
    std::vector<sf::Color> ButtonsLabel = { 
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Red,
        sf::Color::Yellow,
        sf::Color::White,
        sf::Color::Magenta,
        sf::Color::Cyan,
        sf::Color(192,192,192) // Grey
    };

public:
    Grid(unsigned int height, unsigned int width, float scale = 30);
    
};

#endif
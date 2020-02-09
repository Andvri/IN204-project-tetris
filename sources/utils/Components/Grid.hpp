#ifndef GRID_CLASS
#define GRID_CLASS
#include "SFML/Graphics.hpp"
#include "Component.hpp"
#include <vector>


enum ColorAvalibles {
    GREY,
    GREEN,
    BLUE,
    RED,
    YELLOW,
    ORANGE,
    MAGENTA,
    CYAN,
};

class Grid
: public Component
{
private:
    int mHeight;
    int mWidth;
    float mPixel;
    sf::RectangleShape mBackground;
    std::vector<int> mTable;

    std::vector<sf::Color> ButtonsLabel = { 
        sf::Color(192,192,192), // Grey
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Red,
        sf::Color::Yellow,
        sf::Color(255,165,0), // Orange
        sf::Color::Magenta,
        sf::Color::Cyan,
    };

    void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
    

public:
    Grid( int mHeight,  int mWidth, float mPixel = 30);

    virtual bool		isSelectable() const;
    void				setText(const std::string& text);
    virtual bool		update(sf::Time dt);
    virtual void		handleEvent(const sf::Event& event);

    void                setColors(std::vector<int> &v);
    
};

#endif
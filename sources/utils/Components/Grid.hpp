#ifndef GRID_CLASS
#define GRID_CLASS
#include "SFML/Graphics.hpp"
#include "Component.hpp"
#include <vector>

/**
 * @brief build the meshes responsible for making the tetris table
 * 
 */
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
        sf::Color(32,32,32), // Grey
        sf::Color(0,153,0),
        sf::Color(0,0,153),
        sf::Color(153,0,0),
        sf::Color(153,0,76),
        sf::Color::Red,
        sf::Color::Magenta,
        sf::Color::Cyan,
        sf::Color::Transparent
    };

    /**
     * @brief performs the design of the entire table, taking the variables of this class to transform it into the game table
     * 
     * @param target 
     * @param states 
     */
    void				draw(sf::RenderTarget& target, sf::RenderStates states) const;
    

public:
    /**
     * @brief Construct a new Grid object
     * 
     * @param mHeight 
     * @param mWidth 
     * @param mPixel 
     */
    Grid( int mHeight,  int mWidth, float mPixel = 30);

    virtual bool		isSelectable() const;
    void				setText(const std::string& text);
    virtual bool		update(sf::Time dt);
    virtual void		handleEvent(const sf::Event& event);

    /**
     * @brief Set the Colors object
     * 
     * @param v color value in enum
     */
    void                setColors(const std::vector<int> &v);
    
};

#endif

#ifndef BACKGROUND_CLASS
#define BACKGROUND_CLASS
#include "Component.hpp"
#include "SFML/Graphics.hpp"
class Background
    : public Component
{
private:
    sf::Sprite      mBackgroundSprite;
    sf::Texture     mBackground;

private:
    /**
     * @brief Places the background in the current view
     * 
     * @param target 
     * @param states 
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

    /**
     * @brief Construct a new Background object
     * 
     * @param path background
     * @param repeat if the image isn't large enough
     * @param opacity number from 0 to 255 for opacity; 128 for half transparent
     */
    Background(std::string path = "media/images/Galaxy2.png", bool repeat = true, int opacity = 255);

    virtual bool		isSelectable() const;
    virtual bool        update(sf::Time dt);
    virtual void		handleEvent(const sf::Event& event);

    /**
     * @brief Set the Size object
     * 
     * @param rect sf::IntRect object
     */
            void        setSize(sf::IntRect rect);

    /**
     * @brief Set the Path to where is the figure
     * 
     * @param path 
     */
            void        setPath(std::string path);
    
    /**
     * @brief Set the background transparency level 
     * 
     * @param value between 0(total invisble) and 255(normal)
     */
            void        setTransparency(float value);
};


#endif
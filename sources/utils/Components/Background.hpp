
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
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
    Background(const std::string path = "media/images/Galaxy2.png",bool repeat = true);

    virtual bool		isSelectable() const;
    virtual bool        update(sf::Time dt);
    virtual void		handleEvent(const sf::Event& event);
            void        setSize(sf::IntRect rect);
};


#endif
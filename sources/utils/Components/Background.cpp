#include "Background.hpp"

#include "../Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Background::Background(std::string path, bool repeat, int opacity) : 
    Component(),
    mBackgroundSprite(),
    mBackground()
{
    if (!mBackground.loadFromFile(path))
	{
	}

    mBackground.setRepeated(repeat);
    mBackgroundSprite.setTexture(mBackground);
    mBackgroundSprite.setColor(sf::Color(255, 255, 255, opacity));

}

void Background::handleEvent(const sf::Event& event)
{

}

bool Background::isSelectable () const
{
    return false;
}

void Background::setSize(sf::IntRect rect)
{
    mBackgroundSprite.setTextureRect(rect);
}

bool Background::update(sf::Time dt) 
{
    
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    states.transform *= getTransform();
	target.draw(mBackgroundSprite, states);
}

void Background::setPath(std::string path)
{
    mBackground.loadFromFile(path);
    mBackgroundSprite.setTexture(mBackground);
}

void Background::setTransparency(float value)
{
    int mValue = value * 255;
    mBackgroundSprite.setColor(sf::Color(255, 255, 255, mValue));
}
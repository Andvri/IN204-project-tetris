#include "Background.hpp"

#include "../Utility.hpp"

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Background::Background(const std::string path, bool repeat) : 
    Component(),
    mBackgroundSprite(),
    mBackground()
{
    if (!mBackground.loadFromFile(path))
	{
	}

    mBackground.setRepeated(repeat);
    mBackgroundSprite.setTexture(mBackground);

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
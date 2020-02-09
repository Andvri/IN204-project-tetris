#include "Utility.hpp"

const sf::Vector2f Utility::WINDOW_SIZE = sf::Vector2f(1024, 576);

void Utility::centerOrigin(sf::Text& text)
{
	sf::FloatRect bounds = text.getLocalBounds();
	text.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}

void Utility::centerOrigin(sf::Sprite& sprite)
{
	sf::FloatRect bounds = sprite.getLocalBounds();
	sprite.setOrigin(std::floor(bounds.left + bounds.width / 2.f), std::floor(bounds.top + bounds.height / 2.f));
}


const sf::Vector2f Utility::getPositionRelative(sf::Vector2u sv,unsigned int propX, unsigned int propY, int displacementX, int displacementY)
{
	float unityX = sf::Vector2f(sv / propX).x;
	float unityY = sf::Vector2f(sv / propY).y;

	return sf::Vector2f(unityX*displacementX, unityY*displacementY);
}

const sf::Vector2f Utility::getPositionRelative(sf::Vector2f sv,unsigned int propX, unsigned int propY, int displacementX, int displacementY)
{
	sf::Vector2f nv(WINDOW_SIZE.x/propX, WINDOW_SIZE.y/propY);
	float unityX = nv.x;
	float unityY = nv.y;

	return sf::Vector2f(unityX*displacementX, unityY*displacementY);
}

const sf::IntRect Utility::getRectWindow(int displacementX, int displacementY)
{
	return sf::IntRect(displacementX, displacementY, WINDOW_SIZE.x, WINDOW_SIZE.y);
}

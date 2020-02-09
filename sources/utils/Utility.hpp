#ifndef UTILITY_CLASS
#define UTILITY_CLASS

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <cmath>

class Utility
{
public:
	static void centerOrigin(sf::Sprite& sprite);
	static void centerOrigin(sf::Text& text);
	static const sf::Vector2f getPositionRelative(sf::Vector2u sv, unsigned int propX, unsigned int propY, int displacementX = 1, int displacementY = 1);
};

#endif


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
};

#endif


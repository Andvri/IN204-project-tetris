#ifndef UTILITY_CLASS
#define UTILITY_CLASS

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "SFML/Graphics.hpp"

#include <cmath>

class Utility
{
public:
	static void centerOrigin(sf::Sprite& sprite);
	static void centerOrigin(sf::Shape& sprite);
	static void centerOrigin(sf::Text& text);
	static const sf::Vector2f getPositionRelative(sf::Vector2u sv, unsigned int propX, unsigned int propY, int displacementX = 1, int displacementY = 1);
	static const sf::Vector2f getPositionRelative(sf::Vector2f sv, unsigned int propX, unsigned int propY, int displacementX = 1, int displacementY = 1);
	
	static const sf::IntRect getRectWindow(int displacementX = 0, int displacementY = 0 );
	
	static const sf::Vector2f WINDOW_SIZE;


};

#endif


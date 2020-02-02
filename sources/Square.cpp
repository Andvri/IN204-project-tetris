#include "./headers/Square.hpp"

#include "../utils/headers/ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(Square::Type type)
{
	switch (type)
	{
		default:
			return Textures::Red;
	}
}

Square::Square(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Square::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

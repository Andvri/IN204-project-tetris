#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "../../utils/headers/Entity.hpp"
#include "../../utils/headers/ResourceIdentifiers.hpp"

#include <SFML/Graphics/Sprite.hpp>


class Square : public Entity
{
	public:
		enum Type
		{
			Red,
			Blue,
			Yellow,
			Orange,
			Green
		};


	public:
							Square(Type type, const TextureHolder& textures);


	private:
		virtual void		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


	private:
		Type				mType;
		sf::Sprite			mSprite;
};

#endif

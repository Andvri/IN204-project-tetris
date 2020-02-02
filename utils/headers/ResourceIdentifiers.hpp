#ifndef RESOURCEIDENTIFIERS_HPP
#define RESOURCEIDENTIFIERS_HPP


// Forward declaration of SFML classes
namespace sf
{
	class Texture;
	class Font;
}

namespace Textures
{
	enum ID
	{
		DefaultBackground,
	};
}

namespace Fonts
{
	enum ID
	{
		Anurati,
        Blanka
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID>	TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>			FontHolder;

#endif

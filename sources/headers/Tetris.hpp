#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "../../utils/headers/ResourceHolder.hpp"
#include "../../utils/headers/ResourceIdentifiers.hpp"
#include "../../utils/headers/SceneNode.hpp"
#include "../../utils/headers/SpriteNode.hpp"
#include "./Square.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class Tetris : private sf::NonCopyable
{
	public:
		explicit							Tetris(sf::RenderWindow& window);
		void								update(sf::Time dt);
		void								draw();


	private:
		void								loadTextures();
		void								buildScene();


	private:
		enum Layer
		{
			Background,
			SquarePlayer,
			LayerCount
		};


	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;
		TextureHolder						mTextures;

		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;

		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;
		Square*								mPlayerSquare;
};

#endif // TETRIS_HPP

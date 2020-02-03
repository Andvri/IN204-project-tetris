#ifndef TETRIS_HPP
#define TETRIS_HPP

#include "../../utils/headers/ResourceHolder.hpp"
#include "../../utils/headers/ResourceIdentifiers.hpp"
#include "../../utils/headers/SceneNode.hpp"
#include "../../utils/headers/SpriteNode.hpp"
#include "./Square.hpp"

#include "../../utils/headers/CommandQueue.hpp"
#include "../../utils/headers/Command.hpp"


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>


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

		CommandQueue&						getCommandQueue();


	private:
		void								loadTextures();
		void								buildScene();

		void								adaptPlayerPosition();
		void								adaptPlayerVelocity();


	private:
		enum Layer
		{
			Background,
			SquarePlayer,
			SquarePlayer2,
			LayerCount
		};


	private:
		sf::RenderWindow&					mWindow;
		sf::View							mWorldView;
		TextureHolder						mTextures;

		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;
		CommandQueue						mCommandQueue;

		sf::FloatRect						mWorldBounds;
		sf::Vector2f						mSpawnPosition;
		float								mScrollSpeed;
		Square*								mPlayerSquare;
		Square*								mPlayerSquare2;
};

#endif // TETRIS_HPP

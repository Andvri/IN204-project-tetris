#include "./headers/Tetris.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <algorithm>
#include <cmath>


Tetris::Tetris(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerSquare(nullptr)
, mPlayerSquare2(nullptr)
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void Tetris::update(sf::Time dt)
{
	
	// Scroll the world, reset player velocity
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());	
	mPlayerSquare->setVelocity(0.f, 0.f);
	mPlayerSquare2->setVelocity(0.f,0.f);

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);
	adaptPlayerVelocity();

	// Regular update step, adapt position (correct if outside view)
	mSceneGraph.update(dt);
	adaptPlayerPosition();
}

void Tetris::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

CommandQueue& Tetris::getCommandQueue()
{
	return mCommandQueue;
}

void Tetris::loadTextures()
{
	mTextures.load(Textures::Red, "media/images/red.png");
	mTextures.load(Textures::DefaultBackground, "media/images/Galaxy2.png");
}

void Tetris::buildScene()
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::DefaultBackground);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's square
	std::unique_ptr<Square> leader(new Square(Square::Red, mTextures));
	mPlayerSquare = leader.get();
	mPlayerSquare->setPosition(sf::Vector2f(100.0f,50.0f));
	mPlayerSquare->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[SquarePlayer]->attachChild(std::move(leader));

	std::unique_ptr<Square> leader2(new Square(Square::Red, mTextures));
	mPlayerSquare2 = leader2.get();
	mPlayerSquare2->setPosition(sf::Vector2f(200.0f,70.0f));
	mPlayerSquare2->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[SquarePlayer2]->attachChild(std::move(leader2));

}


void Tetris::adaptPlayerPosition()
{
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayerSquare->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerSquare->setPosition(position);



	position = mPlayerSquare2->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerSquare2->setPosition(position);
}

void Tetris::adaptPlayerVelocity()
{
	sf::Vector2f velocity = mPlayerSquare->getVelocity();

	// If moving diagonally, reduce velocity (to have always same velocity)
	if (velocity.x != 0.f && velocity.y != 0.f)
		mPlayerSquare->setVelocity(velocity / std::sqrt(2.f));

	// Add scrolling velocity
	mPlayerSquare->accelerate(0.f, mScrollSpeed);




	velocity = mPlayerSquare2->getVelocity();

	// If moving diagonally, reduce velocity (to have always same velocity)
	if (velocity.x != 0.f && velocity.y != 0.f)
		mPlayerSquare2->setVelocity(velocity / std::sqrt(2.f));

	// Add scrolling velocity
	mPlayerSquare2->accelerate(0.f, mScrollSpeed);
}

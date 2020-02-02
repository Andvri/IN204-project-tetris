#include "./headers/Tetris.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


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
{
	loadTextures();
	buildScene();

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void Tetris::update(sf::Time dt)
{
	// Scroll the world
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());	

	// Move the player sidewards (plane scouts follow the main square
	sf::Vector2f position = mPlayerSquare->getPosition();
	sf::Vector2f velocity = mPlayerSquare->getVelocity();

	// If player touches borders, flip its X velocity
	if (position.x <= mWorldBounds.left + 150.f
	 || position.x >= mWorldBounds.left + mWorldBounds.width - 150.f)
	{
		velocity.x = -velocity.x;
		mPlayerSquare->setVelocity(velocity);
	}

	// Apply movements
	mSceneGraph.update(dt);
}

void Tetris::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
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
	mPlayerSquare->setPosition(mSpawnPosition);
	mPlayerSquare->setVelocity(40.f, mScrollSpeed);
	mSceneLayers[SquarePlayer]->attachChild(std::move(leader));

}

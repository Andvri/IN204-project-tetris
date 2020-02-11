#include "GameScene.hpp"
#include "../utils/Utility.hpp"


GameScene::GameScene(StateManager& stack, Context context) 
:   State(stack, context),
    mBackground(),
	mNextRec(),
	mPlayerText("Player info: ", "media/fonts/Blanka-Regular.otf", true, 30),
	mScoreText("Score: ", "media/fonts/Blanka-Regular.otf", true, 30),
	mNextText("Next piece: ", "media/fonts/Blanka-Regular.otf", true, 30)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2f ws(window.getSize());

	mBackground.setSize(sf::IntRect(0, 0, window.getSize().x, window.getSize().y));

	mPlayerText.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 1, 4));
	mScoreText.setPosition(Utility::getPositionRelative(ws, 16u, 8u, 1, 1));
	mNextText.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 7, 1));



}


void GameScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);
	
	if(mPlayerText.isActive()) window.draw(mPlayerText);
	if(mScoreText.isActive()) window.draw(mScoreText);
	if(mNextText.isActive()) window.draw(mNextText);
	window.draw(mNextRec);
}

bool GameScene::update(sf::Time dt)
{
	return true;
}

bool GameScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::P:
			requestStackPush(States::Pause);
			break;
		
		default:
			break;
		}
	}

	return true;
}
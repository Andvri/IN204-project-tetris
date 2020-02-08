#include "GameScene.hpp"



GameScene::GameScene(StateManager& stack, Context context) :       State(stack, context),
    mCircle()
{
    mCircle.setRadius(10);
    mCircle.setFillColor(sf::Color::Yellow);
	mCircle.setPosition(context.window->getView().getSize() / 2.f);
}


void GameScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mCircle);
}

bool GameScene::update(sf::Time dt)
{
	return true;
}

bool GameScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::Title);
	}

	return true;
}
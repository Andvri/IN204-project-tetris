#include "MenuScene.hpp"



MenuScene::MenuScene(StateManager& stack, Context context) :       
	State(stack, context),
    mRectangle()
{
    mRectangle.setSize(sf::Vector2f(100,100));
    mRectangle.setFillColor(sf::Color::Yellow);
	mRectangle.setPosition(context.window->getView().getSize() / 2.f);
}


void MenuScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mRectangle);
}

bool MenuScene::update(sf::Time dt)
{
	return true;
}

bool MenuScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::Game);
	}

	return true;
}
#include "./TitleScene.hpp"



TitleScene::TitleScene(StateManager& stack, Context context) :       State(stack, context),
    mRectangle()
{
    mRectangle.setSize(sf::Vector2f(10,10));
    mRectangle.setFillColor(sf::Color::Red);
	mRectangle.setPosition(context.window->getView().getSize() / 2.f);
}


void TitleScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mRectangle);
}

bool TitleScene::update(sf::Time dt)
{
	return true;
}

bool TitleScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::Menu);
	}

	return true;
}
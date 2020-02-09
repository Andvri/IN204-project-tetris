#include "./TitleScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>


TitleScene::TitleScene(StateManager& stack, Context context) :
	State(stack, context),
	mTitle("TE TRIS 20 20","media/fonts/Blanka-Regular.otf", true, 100, false, true),
    mMsg("Press any key to start","media/fonts/Blanka-Regular.otf", true, 30, true, false),
    mCopy("2020 © JF Studios","media/fonts/Blanka-Regular.otf", true, 20),
	mBackground()
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u ws(window.getSize());
	
	
	
	
	mBackground.setSize(sf::IntRect(0, 0, window.getSize().x,window.getSize().y));

	mTitle.setPosition(Utility::getPositionRelative(ws, 2u, 4u));
	mMsg.setPosition(Utility::getPositionRelative(ws, 2u, 4u, 1, 2));
	mCopy.setPosition(Utility::getPositionRelative(ws, 2u, 4u, 1, 3));


}


void TitleScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);

	if (mTitle.isActive())
		window.draw(mTitle);

	if (mMsg.isActive())
		window.draw(mMsg);

	if (mCopy.isActive())
		window.draw(mCopy);
}

bool TitleScene::update(sf::Time dt)
{
	mTitle.update(dt);
	mMsg.update(dt);
	mCopy.update(dt);

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
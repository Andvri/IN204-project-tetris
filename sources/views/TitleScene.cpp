#include "./TitleScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>


TitleScene::TitleScene(StateManager& stack, Context context) :
	State(stack, context),
	mTitle("TE TRIS 20 20","media/fonts/Blanka-Regular.otf", true, 100, false, true),
    mMsg("Press any key to start","media/fonts/Blanka-Regular.otf", true, 30, true, false),
    mCopy("2020 © JF Studios","media/fonts/Blanka-Regular.otf", true, 20),
	mBackgroundSprite(),
	mBackground()
{
	if (!mBackground.loadFromFile("media/images/Galaxy2.png"))
	{
	}
	sf::RenderWindow& window = *getContext().window;
	mBackground.setRepeated(true);
	mBackgroundSprite.setTexture(mBackground);
	mBackgroundSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x,window.getSize().y));



	/**
	 * 
	 *	TODO:  Optimize centering
	 */
	sf::Vector2f ws(window.getSize() / 4u);

	float propX = sf::Vector2f(window.getSize() / 2u).x;
	float propY = ws.y;

	mTitle.setPosition(sf::Vector2f(propX, propY));
	mMsg.setPosition(sf::Vector2f(propX, propY*2));
	mCopy.setPosition(sf::Vector2f(propX, propY*3));


}


void TitleScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

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
#include "./TitleScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>


TitleScene::TitleScene(StateManager& stack, Context context) :
	State(stack, context),
	mTitle(),
    mMsg(),
    mCopy(),
	mFont(),
	mBackgroundSprite(),
	mBackground(),
	mShowText(true),
	mTextEffectTime(sf::Time::Zero)
{
	if (!mBackground.loadFromFile("media/images/Galaxy2.png"))
	{
	}
	if(!mFont.loadFromFile("media/fonts/Blanka-Regular.otf"))
	{
	}

	sf::RenderWindow& window = *getContext().window;
	mBackground.setRepeated(true);
	mBackgroundSprite.setTexture(mBackground);
	mBackgroundSprite.setTextureRect(sf::IntRect(0, 0, window.getSize().x,window.getSize().y));
	mTitle.setFont(mFont);
	mTitle.setString("Press any key to start");
	Utility::centerOrigin(mTitle);
	mTitle.setPosition(sf::Vector2f(context.window->getSize() / 2u));
}


void TitleScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	if (mShowText)
		window.draw(mTitle);
}

bool TitleScene::update(sf::Time dt)
{
	mTextEffectTime += dt;

	if (mTextEffectTime >= sf::seconds(0.5f))
	{
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}

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
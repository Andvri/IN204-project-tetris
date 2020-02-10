#include "HelpScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>

HelpScene::HelpScene(StateManager& stack, Context context) :       
	State(stack, context),
    mTitleHelp("HELP: ", "media/fonts/Blanka-Regular.otf", true, 100),
    mSubTitleButton("Buttons :", "media/fonts/Blanka-Regular.otf", true, 25),
    mSubTitleText(": Function", "media/fonts/Blanka-Regular.otf", true, 25),
    mReturn("Return", "media/fonts/Blanka-Regular.otf", true, 15, true),
    mBackground()
{
    sf::RenderWindow& window = *getContext().window;
	sf::Vector2f ws(window.getSize());
	
	mBackground.setSize(Utility::getRectWindow());
	
	mTitleHelp.setPosition(Utility::getPositionRelative(ws, 2u, 4u, 1, 1));
	mSubTitleButton.setPosition(Utility::getPositionRelative(ws, 6u, 6u, 1, 3));
	mSubTitleText.setPosition(Utility::getPositionRelative(ws, 6u, 6u, 5, 3));
	mReturn.setPosition(Utility::getPositionRelative(ws, 12u, 12u, 11, 11));

	for (int i = 0; i < mTextsLeft.size(); i++)
	{
		Label *Text = new Label(mTextsLeft[i], "media/fonts/Blanka-Regular.otf", true, 15, (i==0));
		Text->setPosition(Utility::getPositionRelative(ws, 10u, 12u, 3, i + 7));

		Label *Text2 = new Label(mTextsRight[i], "media/fonts/Blanka-Regular.otf", true, 15, (i==0));
		Text2->setPosition(Utility::getPositionRelative(ws, 10u, 12u, 7, i + 7));

		mMsgButtons.push_back(Text);
		mMsgExplain.push_back(Text2);
	}

}

void HelpScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);

	if (mTitleHelp.isActive())	window.draw(mTitleHelp);
	if (mSubTitleButton.isActive())	window.draw(mSubTitleButton);
	if (mSubTitleText.isActive())	window.draw(mSubTitleText);
	if (mReturn.isActive())	window.draw(mReturn);

	for (auto &&i : mMsgButtons)
	{
		window.draw(*i);
	}

	for (auto &&j : mMsgExplain)
	{
		window.draw(*j);
	}
}

bool HelpScene::update(sf::Time dt)
{
	
	return true;
}

bool HelpScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Return:
			requestStackPop();
			requestStackPush(States::Menu);
			break;
		
		default:
			break;
		}
	}

	return true;
}
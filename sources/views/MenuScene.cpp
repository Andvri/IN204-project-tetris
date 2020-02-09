#include "MenuScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>

MenuScene::MenuScene(StateManager& stack, Context context) :       
	State(stack, context),
    mRectangle(),
	mBackground(),
	mButtons(),
	mButtonSelect(0)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u ws(window.getSize());
	
	mBackground.setSize(sf::IntRect(0, 0, window.getSize().x,window.getSize().y));


	for (int i = 0; i < ButtonsLabel.size(); i++)
	{
		Button *b = new Button(ButtonsLabel[i],"media/fonts/Blanka-Regular.otf", true, 30, (i==0));
		b->setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, i +5));
		mButtons.push_back(b);
	}
	
	
}


void MenuScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);

	for (auto &&i : mButtons)
	{
		window.draw(*i);
	}
	
	
}

bool MenuScene::update(sf::Time dt)
{
	return true;
}

bool MenuScene::handleEvent(const sf::Event& event)
{
	if (event.key.code == sf::Keyboard::N)
	{
		requestStackPop();
		requestStackPush(States::Game);
	}

	if (event.type == event.KeyPressed) 
	{
		if (event.key.code == sf::Keyboard::Tab)
		{
			int next = (mButtonSelect + 1) % ButtonsLabel.size();
		
			mButtons[mButtonSelect]->deselect();
			mButtons[next]->select();

			mButtonSelect = next;
		}
	}

	return true;
}
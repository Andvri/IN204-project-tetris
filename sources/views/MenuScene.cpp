#include "MenuScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>

MenuScene::MenuScene(StateManager& stack, Context context) :       
	State(stack, context),
    mRectangle(),
	mBackground(),
	mButton("Singleplayer","media/fonts/Blanka-Regular.otf", true, 30, true),
	mButton2("Multiplayer","media/fonts/Blanka-Regular.otf", true, 30),
	mButtons()
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2u ws(window.getSize());
	
	mBackground.setSize(sf::IntRect(0, 0, window.getSize().x,window.getSize().y));

	mButton.setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, 7));
	mButton.activate();

	mButton2.setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, 8 ));
	
	Button *b = new Button("Ricardo Rico","media/fonts/Blanka-Regular.otf", true, 30);
	b->setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, 6 ));

	Button *g = new Button("Ve Fabr","media/fonts/Blanka-Regular.otf", true, 30);
	g->setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, 5 ));
	mButtons.push_back(g);
	mButtons.push_back(b);

	
}


void MenuScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);
	window.draw(mButton);
	window.draw(mButton2);

	for (auto &&i : mButtons)
	{
		window.draw(*i);
	}
	
	
}

bool MenuScene::update(sf::Time dt)
{
	mButton.update(dt);
	mButton2.update(dt);
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
			if(mButton.isSelected()){
				mButton.deselect();
				mButton2.select();
			}else{
				mButton2.deselect();
				mButton.select();
			}
		}
	}

	return true;
}
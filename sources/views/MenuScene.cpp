#include "MenuScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>

MenuScene::MenuScene(StateManager& stack, Context context) :       
	State(stack, context),
    mRectangle(),
	mBackground(),
	mButtons(),
	mButtonSelect(0),
	mMenuTitle("MENU", "media/fonts/Blanka-Regular.otf", true, 100, false, true)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2f ws(window.getSize());
	
	mBackground.setSize(Utility::getRectWindow());

	mMenuTitle.setPosition(Utility::getPositionRelative(ws, 2u, 4u, 1, 1));

	for (int i = 0; i < ButtonsLabel.size(); i++)
	{
		Button *b = new Button(ButtonsLabel[i],"media/fonts/Blanka-Regular.otf", true, 30, (i==0));
		b->setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, i +5));

		if (i == ButtonsLabel.size()-1)
			b->setCallback([this](){
				requestStateClear();
			});
		else 
			b->setCallback([this](){
				requestStackPop();
				requestStackPush(States::Title);
			});
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

	if(mMenuTitle.isActive()) window.draw(mMenuTitle);
	
	
}

bool MenuScene::update(sf::Time dt)
{
	mMenuTitle.update(dt);
	return true;
}

bool MenuScene::handleEvent(const sf::Event& event)
{

	if (event.type == event.KeyPressed) 
	{		
		switch (event.key.code)
		{
		case sf::Keyboard::Tab:
			moveFocus(true);
			break;
		case sf::Keyboard::Up:
			moveFocus(false);
			break;
		case sf::Keyboard::Down:
			moveFocus(true);
			break;
		case sf::Keyboard::Return:
			mButtons[mButtonSelect]->select();
		}
	}

	return true;
}

void MenuScene::moveFocus(bool asc)
{
	int next;

	if (mButtonSelect == 0 && !asc)
		next = mButtons.size() - 1;
	else
		next = (mButtonSelect + ((asc) ? 1 : -1) ) % ButtonsLabel.size();
	
	mButtons[mButtonSelect]->toggle();
	mButtons[next]->toggle();

	mButtonSelect = next;
}
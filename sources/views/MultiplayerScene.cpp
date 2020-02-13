#include "MultiplayerScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>


MultiplayerScene::MultiplayerScene(StateManager& stack, Context contex)
:   State(stack, contex),
    mBackground(),
    mMultiplayerTitle("MultiPlayer", "media/fonts/Blanka-Regular.otf", true, 100, false, true, sf::Color::Green),
    mButtons(),
    mButtonChoice(0),
	th(nullptr)
{
    sf::RenderWindow& window = *getContext().window;
    sf::Vector2f ws(window.getSize());

    mBackground.setSize(Utility::getRectWindow());

    mMultiplayerTitle.setPosition(Utility::getPositionRelative(ws, 2u, 4u, 1, 1));
    for (int i = 0; i < ButtonsLabel.size(); i++)
    {
        Button *b = new Button(ButtonsLabel[i], "media/fonts/Blanka-Regular.otf", true, 30, (i==0));
        b->setPosition(Utility::getPositionRelative(ws, 2u, 10u, 1, i +5));

        if (i == ButtonsLabel.size()-1)
        {
            b->setCallback([this](){
				requestStackPop();
				requestStackPush(States::Menu);
			});
            b->setPosition(Utility::getPositionRelative(ws, 2u, 20u, 1, 19));
        }
			
		else if (ButtonsLabel[i] == "Create")
		{
				(getContext().player)->establishRole(true);
			b->setCallback([this](){
				th = new sf::Thread([&] () {
					(getContext().player)->establishConnection(true);
				});
				th->launch();
				
				//requestStackPop();
				//requestStackPush(States::Game);
			});
		}
		else if (ButtonsLabel[i] == "Join")
		{

			(getContext().player)->establishRole(false);
			b->setCallback([this](){
				th = new sf::Thread([&] () {
					(getContext().player)->establishConnection(false);
				});
				th->launch();
				//requestStackPop();
				//requestStackPush(States::Title);
			});
		}
		mButtons.push_back(b);
    }
}

void MultiplayerScene::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.draw(mBackground);

    if (mMultiplayerTitle.isActive()) window.draw(mMultiplayerTitle);

    for (auto &&i : mButtons){
        window.draw(*i);
    }
}

bool MultiplayerScene::update(sf::Time dt)
{
    mMultiplayerTitle.update(dt);
    return true;
}

bool MultiplayerScene::handleEvent(const sf::Event& event){
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
			mButtons[mButtonChoice]->select();
		}
	}
}

void MultiplayerScene::moveFocus(bool asc)
{
	int next;

	if (mButtonChoice == 0 && !asc)
		next = mButtons.size() - 1;
	else
		next = (mButtonChoice + ((asc) ? 1 : -1) ) % ButtonsLabel.size();
	
	mButtons[mButtonChoice]->toggle();
	mButtons[next]->toggle();

	mButtonChoice = next;
}
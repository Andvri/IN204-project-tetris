#include "MultiplayerScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>


MultiplayerScene::MultiplayerScene(StateManager& stack, Context contex)
:   State(stack, contex),
    mBackground(),
    mMultiplayerTitle("MultiPlayer", "media/fonts/Blanka-Regular.otf", true, 100, false, true, sf::Color::Green),
    mButtons(),
    mButtonChoice(0),
	th(nullptr),
	waitResponse(false),
	waitMessage("WAITING FOR PLAYERS", "media/fonts/Blanka-Regular.otf", true, 40, false, false)
{
    sf::RenderWindow& window = *getContext().window;
    sf::Vector2f ws(window.getSize());

    mBackground.setSize(Utility::getRectWindow());
	waitMessage.setPosition(Utility::getPositionRelative(ws, 2u, 2u, 1, 1));
	waitMessage.deactivate();
	waitMessage.setBorder(sf::Color::Black, sf::Color::White, 4);

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
					handleMultiplayer(true);
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
					handleMultiplayer(false);
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
		if (i->isActive())
		{
			window.draw(*i);
		}
    }
	if(waitMessage.isActive()) window.draw(waitMessage);
}

bool MultiplayerScene::update(sf::Time dt)
{
    mMultiplayerTitle.update(dt);
	if(waitMessage.isActive())  waitMessage.update(dt);
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
	if(waitResponse)
		return;


	int next;

	if (mButtonChoice == 0 && !asc)
		next = mButtons.size() - 1;
	else
		next = (mButtonChoice + ((asc) ? 1 : -1) ) % ButtonsLabel.size();
	
	mButtons[mButtonChoice]->toggle();
	mButtons[next]->toggle();

	mButtonChoice = next;
}

void    MultiplayerScene::handleMultiplayer(bool createConnection)
{	
	std::string msg = (createConnection) ? "WAITING FOR PLAYERS": "SEARCHING PLAYERS";
	waitResponse = true;
	waitMessage.setText(msg);
	waitMessage.activate();
	(getContext().player)->establishConnection(createConnection);
	waitMessage.deactivate();
	waitResponse = false;
	

	if ((getContext().player)->getMultiplayer()) 
	{
		requestStackPop();
		requestStackPush(States::Game);
	}
	
}
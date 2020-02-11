#include "PauseScene.hpp"
#include "../utils/Utility.hpp"
#include <iostream>

PauseScene::PauseScene(StateManager& stack, Context context):
    State(stack, context),
    mBackground(),
    mButtons(),
    mButtonSelect(0),
    mPauseTitle("PAUSE", "media/fonts/Blanka-Regular.otf", true, 40)
{
    sf::RenderWindow& window = *getContext().window;
	sf::Vector2f ws(window.getSize());
	
	mBackground.setSize(Utility::getRectWindow());
    mBackground.setTransparency(0.5f);

	mPauseTitle.setPosition(Utility::getPositionRelative(ws, 2u, 2u, 1, 1));

    for (int i = 0; i < mButtonLabels.size(); i++){
        Button *b = new Button(mButtonLabels[i], "media/fonts/Blanka-Regular.otf", true, 15, (i==0));
        b->setPosition(Utility::getPositionRelative(ws, 2u, 12u, 1, i +7));

        if (i == mButtonLabels.size()-1)
			b->setCallback([this](){
				requestStateClear();
			});
        else if (mButtonLabels[i] == "Resume")
			b->setCallback([this](){
				getContext().player->setPause(false);
				requestStackPop();
			});
        else if (mButtonLabels[i] == "Return")
			b->setCallback([this](){
				requestStateClear();
				requestStackPush(States::Menu);
			});

        mButtons.push_back(b);
    }
}

void PauseScene::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.draw(mBackground);
    if (mPauseTitle.isActive()) window.draw(mPauseTitle);

    for (auto &&i : mButtons)
	{
		window.draw(*i);
	}

}

bool PauseScene::update(sf::Time dt)
{
	return true;
}

bool PauseScene::handleEvent(const sf::Event& event)
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

void PauseScene::moveFocus(bool asc)
{
	int next;

	if (mButtonSelect == 0 && !asc)
		next = mButtons.size() - 1;
	else
		next = (mButtonSelect + ((asc) ? 1 : -1) ) % mButtonLabels.size();
	
	mButtons[mButtonSelect]->toggle();
	mButtons[next]->toggle();

	mButtonSelect = next;
}
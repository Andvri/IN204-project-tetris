#include "GameScene.hpp"
#include "../utils/Utility.hpp"


GameScene::GameScene(StateManager& stack, Context context) 
:   State(stack, context),
    mGrid(21, 5, 20)
{
	mGrid.setPosition(Utility::getPositionRelative(context.window->getView().getSize(), 8, 2, 1, 1));

	std::vector<int> colors;
	for (int i = 0; i< 21*5; i++) {
		colors.push_back(i%8);
	}

	mGrid.setColors(colors);

}


void GameScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mGrid);
}

bool GameScene::update(sf::Time dt)
{
	return true;
}

bool GameScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::Title);
	}

	return true;
}
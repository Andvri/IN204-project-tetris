#include "GameScene.hpp"
#include "../utils/Utility.hpp"

#include <iostream>

GameScene::GameScene(StateManager& stack, Context context) 
:   State(stack, context),
    mBackground(),
	mNextRec(),
	mPlayerText("Player info: ", "media/fonts/Blanka-Regular.otf", true, 30),
	mScoreText("Score: ", "media/fonts/Blanka-Regular.otf", true, 30),
	mNextText("Next piece: ", "media/fonts/Blanka-Regular.otf", true, 30),
	mGrid(20, 10, 20),
	timeSinceLastUpdate(sf::Time::Zero),
	timeLevel(sf::Time::Zero),
	mMatrix(10, 20),
	mTetromino(nullptr)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2f ws(window.getSize());

	mBackground.setSize(Utility::getRectWindow());

	mPlayerText.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 1, 4));
	mScoreText.setPosition(Utility::getPositionRelative(ws, 16u, 8u, 1, 1));
	mNextText.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 7, 1));

    mTetromino = new Tetromino(10, 20);
	mTetromino->setCollisionEvent([this](CollisionDirection cd)
			  {
                 handlerCollisionEvent(cd);
			  }
			  );
	mGrid.setPosition(Utility::getPositionRelative(ws, 2u, 2u,1, 1));
}


void GameScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);

    

	mGrid.setColors((mMatrix + (*mTetromino)).getPos());
	
	if(mPlayerText.isActive()) window.draw(mPlayerText);
	if(mScoreText.isActive()) window.draw(mScoreText);
	if(mNextText.isActive()) window.draw(mNextText);
	window.draw(mNextRec);
	window.draw(mGrid);
}

bool GameScene::update(sf::Time dt)
{	
	timeSinceLastUpdate += dt;
	timeLevel+= dt;
	
	if (timeLevel >= sf::seconds(0.1f)) {
	  (*mTetromino)++;
      timeLevel = sf::Time::Zero;
	}
    

	mPlayerText.setText(getHumanTime(dt));
	return true;
}

bool GameScene::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
		    case (sf::Keyboard::P):
			{
				requestStackPop();
			    requestStackPush(States::Title);
			    break;
			}
			case (sf::Keyboard::Left):
			case (sf::Keyboard::A):
			{
				*mTetromino = (*mTetromino - 1);
				break;
			}
			case (sf::Keyboard::Right):
			case (sf::Keyboard::D):
			{
				*mTetromino = (*mTetromino + 1);
				break;
			}
		
		}
	}

	return true;
}

std::string GameScene::getHumanTime(sf::Time dt) const
{
	std::string text;
	int seconds = timeSinceLastUpdate.asSeconds();
	int hours   = (seconds / 3600);

	text += (hours < 10) ? ("0"):"";
	text +=	std::to_string(hours) + " : ";

	seconds -= (hours*3600);
	int minutes = (seconds / 60);

	text += (minutes < 10) ? ("0"):"";
	text +=	std::to_string(minutes) + " : ";


	seconds -= (minutes*60);
	text += (seconds < 10) ? ("0"):"";
	text += std::to_string(seconds)	;
	
		
	return  text;
}

void GameScene::handlerCollisionEvent( CollisionDirection cd)
{
	if (cd == SOUTH)
		  {
			  mMatrix = (mMatrix + (*mTetromino));
			  mTetromino = new Tetromino(10, 20);
			  mTetromino->setCollisionEvent([this](CollisionDirection cd)
			  {
                 handlerCollisionEvent(cd);
			  }
			  );
		  }
}
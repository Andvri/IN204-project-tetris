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
	mNextGrid(20, 10, 12),
	timeSinceLastUpdate(sf::Time::Zero),
	timeLevel(sf::Time::Zero),
	mMatrix(10, 20),
	mNextMatrix(10, 20),
	mTetromino(nullptr),
	mPlayGame(true),
	mPause(false),
	mHardDrop(false),
	mNextTetromino(nullptr)
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
	generateNextTetromino();
	mGrid.setPosition(Utility::getPositionRelative(ws, 2u, 2u,1, 1));

	mNextGrid.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 7, 4));
}


void GameScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);

    
	mNextGrid.setColors((mNextMatrix + (*mNextTetromino)).getPos());
	mGrid.setColors((mMatrix + (*mTetromino)).getPos());
	
	if(mPlayerText.isActive()) window.draw(mPlayerText);
	if(mScoreText.isActive()) window.draw(mScoreText);
	if(mNextText.isActive()) window.draw(mNextText);
	window.draw(mNextRec);
	window.draw(mGrid);
	window.draw(mNextGrid);
}

bool GameScene::update(sf::Time dt)
{	
	if (!(getContext()).player->getPause()) 
	{
		timeSinceLastUpdate += dt;
		timeLevel+= dt;
		
		if (timeLevel >= sf::seconds(1.0f)) {
		descend();
		}
		

		mPlayerText.setText(getHumanTime(dt));
	}
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
				if (!(getContext()).player->getPause()) {

					(getContext()).player->setPause(true);
					requestStackPush(States::Pause);
				}
			    break;
			}
		}

		if (mPlayGame && !(getContext()).player->getPause()){
			switch (event.key.code)
			{
			case (sf::Keyboard::Left):
			case (sf::Keyboard::A):
			{
				Tetromino tmp = (*mTetromino - 1);
				*mTetromino = (tmp == mMatrix) ? tmp : *mTetromino;
				break;
			}
			case (sf::Keyboard::Right):
			case (sf::Keyboard::D):
			{
				Tetromino tmp = (*mTetromino + 1);
				*mTetromino = (tmp == mMatrix) ? tmp : *mTetromino;
				break;
			}
			case (sf::Keyboard::Down):
			case (sf::Keyboard::S):
			{
				descend();
				break;
			}
			case (sf::Keyboard::Up):
			{
				Tetromino tmp = mTetromino->cloneAndRotate();
				tmp.correctBorder();
				*mTetromino = (mMatrix == tmp) ? tmp : *mTetromino; 
				
				break;
			}
            case (sf::Keyboard::R):
			{
				Tetromino tmp = mTetromino->cloneAndRotate(Direction::COUNTERCLOCKWISE);
				tmp.correctBorder();
				*mTetromino = (mMatrix == tmp) ? tmp : *mTetromino; 
				
				break;
			}

			case (sf::Keyboard::Space):
			{
				mHardDrop = true;
				while (mHardDrop)
				{
					descend();
				}
				
				
				break;
			}
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
	mHardDrop = false;
	if (mPlayGame) {

       if (cd == SOUTH)
		  {
			mPlayGame = mTetromino->offsetAxis();
			if (!mPlayGame) {
				std::cout << "END GAME" << std::endl;
				return;

			} else {

				mMatrix = (mMatrix + (*mTetromino));
			}

			 
			updateNextTetromino();
			mTetromino = mNextTetromino;
			generateNextTetromino();
			mTetromino->setCollisionEvent([this](CollisionDirection cd)
				{
						handlerCollisionEvent(cd);
				}
			);
		  }
	}
	
}

void GameScene::descend()
{
	Tetromino tmp = *mTetromino;
	tmp.disableEvent();
	tmp++;
	tmp.enableEvent();
	
	if (mMatrix == tmp) {
	    (*mTetromino)++;
		
	} else
	{
		handlerCollisionEvent(SOUTH);
	}
	timeLevel = sf::Time::Zero;
}

void GameScene::generateNextTetromino()
{
	mNextTetromino = new Tetromino(10,20);

	(*mNextTetromino) = (*mNextTetromino) + 5;
	for (size_t i = 0; i < 10; i++)
	{
			(*mNextTetromino)++;
	}

}
void GameScene::updateNextTetromino()
{
	(*mNextTetromino) = (*mNextTetromino) - 5;
	for (size_t i = 0; i < 10; i++)
	{
			(*mNextTetromino)--;
	}
}
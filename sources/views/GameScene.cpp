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
	mScoreValue("0 ", "media/fonts/Blanka-Regular.otf", true, 30),
	mGrid(20, 10, 20),
	timeSinceLastUpdate(sf::Time::Zero),
	timeLevel(sf::Time::Zero),
	mMatrix(10, 20),
	mTetromino(nullptr),
	mPlayGame(true),
	mPause(false),
	mHardDrop(false),
	mNextTetromino(nullptr),
	mPoints(0),
	mTimeNotification(sf::Time::Zero),
    mNotification("GAME OVER", "media/fonts/Blanka-Regular.otf", true, 80, true),
	mNotification2("Restart in: 0 ", "media/fonts/Blanka-Regular.otf", true, 30)
{
	sf::RenderWindow& window = *getContext().window;
	sf::Vector2f ws(window.getSize());

	mBackground.setSize(Utility::getRectWindow());

	mPlayerText.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 1, 4));
	mScoreText.setPosition(Utility::getPositionRelative(ws, 16u, 8u, 2, 1));
	mScoreValue.setPosition(Utility::getPositionRelative(ws, 16u, 8u, 2, 2));
	mNextText.setPosition(Utility::getPositionRelative(ws, 8u, 8u, 7, 1));
	mNotification.setPosition(Utility::getPositionRelative(ws, 2u, 2u, 1, 1));

	mNotification2.setPosition(Utility::getPositionRelative(ws, 2u, 8u, 1, 7));

    
	restart();


	mGrid.setPosition(Utility::getPositionRelative(ws, 2u, 2u,1, 1));

	mNotification.deactivate();
	mNotification.setBorder(sf::Color::Black, sf::Color::White, 5);
	mNotification2.deactivate();
	mNotification2.setBorder(sf::Color::Black, sf::Color::White, 4);
}


void GameScene::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackground);

    Grid tmpGrid(20,10, 12);
	Matrix tmpMatrix(10,20);

	Tetromino tmpTetromino(
		mNextTetromino->getBorderX(),
		mNextTetromino->getBorderY(),
		5,
		10,
		mNextTetromino->getStucture(),
		mNextTetromino->getColor()
	);
	
	tmpMatrix = tmpMatrix + (tmpTetromino);
	
	tmpGrid.setColors((tmpMatrix).getPos());
	tmpGrid.setPosition(Utility::getPositionRelative(sf::Vector2f(window.getSize()), 8u, 8u, 7, 4));


	mGrid.setColors((mMatrix + (*mTetromino)).getPos());
	
	if(mPlayerText.isActive()) window.draw(mPlayerText);
	if(mScoreText.isActive()) window.draw(mScoreText);
	if(mScoreValue.isActive()) window.draw(mScoreValue);
	if(mNextText.isActive()) window.draw(mNextText);
	window.draw(mNextRec);
	window.draw(mGrid);
	window.draw(tmpGrid);

	if(mNotification.isActive()) window.draw(mNotification);
	if(mNotification2.isActive()) window.draw(mNotification2);
}

bool GameScene::update(sf::Time dt)
{	
	if ((getContext()).player->getRestart()) 
	{
		(getContext()).player->setRestart(false);
		restart();
	}

	
	if (!(getContext()).player->getPause()) 
	{
		timeSinceLastUpdate += dt;
		timeLevel+= dt;
		mTimeNotification -=dt;
		
		if (timeLevel >= sf::seconds(1.0f)) {
			descend();
		}

		if (mTimeNotification <= sf::seconds(0.0f) && mNotification.isActive()) {
			mNotification.deactivate();
			mNotification2.deactivate();
			restart();
		}
		else {
			mNotification2.setText("Restart in: " + std::to_string(((int)mTimeNotification.asSeconds())) + " ");
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
				mNotification.activate();
				mNotification2.activate();
				mNotification.setText("Game Over");
				mTimeNotification = sf::seconds(10);
				return;
			} else {

				mMatrix = (mMatrix + (*mTetromino));
				int lines = mMatrix.updateLines((*mTetromino));
				int points = 0;
				switch (lines)
				{
				case 1:
					points = 40;
					break;
				case 2:
					points = 100;
					break;
				case 3:
					points = 300;
					break;
				case 4:
					points = 1200;
					break;
				}
				mPoints+= points;
				mScoreValue.setText(std::to_string(mPoints));

				
				updateNextTetromino();
				mTetromino = mNextTetromino;
				mNextTetromino = new Tetromino(10,20);
				mTetromino->setCollisionEvent([this](CollisionDirection cd)
					{
							handlerCollisionEvent(cd);
					}
				);
			}

			 
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




void GameScene::restart()
{

	timeLevel = sf::Time::Zero;
	timeSinceLastUpdate = sf::Time::Zero;

	(getContext()).player->setPause(false);
	mScoreValue.setText("0");
	mGrid.restart();
	mMatrix.restart();
	mPlayGame = true;
	/**
	 *  TODO: Improve and use dynamic constants
	 */
	mTetromino = new Tetromino(10, 20);
	mTetromino->setCollisionEvent([this](CollisionDirection cd)
			  {
                 handlerCollisionEvent(cd);
			  }
			  );

	mNextTetromino = new Tetromino(10,20);

}
void GameScene::updateNextTetromino()
{
	
}
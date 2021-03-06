#include "Player.hpp"

Player::Player(/* args */):
    mLevel(1),
    mScore(0),
    mPause(false)
{
}

Player::Player(bool pause, int score, int level) :
    mLevel(level),
    mScore(score),
    mPause(pause),
    mMultiplayer(false),
    mRestart(false),
    mMultiplayerController()
{
}


Player::~Player()
{
}


bool Player::getPause()
{
    return mPause;
}

int Player::getScore()
{
    return mScore;
}
int Player::getLevel()
{
    return mLevel;
}

int Player::getMultiplayer()
{
    return mMultiplayer;
}
int Player::getRestart()
{
    return mRestart;
}

void Player::setPause(bool pause)
{
    mPause = pause;
}

void Player::setScore(int score)
{
    mScore = score;
}
void Player::setLevel(int level)
{
    mLevel = level;
}

void Player::setMultiplayer(bool multiplayer)
{
    mMultiplayer = multiplayer;
}
void Player::setRestart(bool restart)
{
    mRestart = restart;
}


void Player::establishConnection(bool create)
{
    RESPONSE_STATUS r;
    if (create)
    {
        r = mMultiplayerController.listenConection();
    }
    else 
    {
        r = mMultiplayerController.searchConection();
    }
    setMultiplayer(r != RESPONSE_STATUS::NONE_RESPONSE);
}

void Player::establishRole(bool create)
{
    mMultiplayerController.establishPort(create);
}


void Player::recvData(std::vector<int> &v)
{
    mMultiplayerController.recvData(v);
}
void Player::sendData(std::vector<int> v)
{
    mMultiplayerController.sendData(v);
}
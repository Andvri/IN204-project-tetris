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
    mPause(pause)
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


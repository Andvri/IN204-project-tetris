#ifndef GAMESCENE_CLASS
#define GAMESCENE_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Grid.hpp"
#include "../game/Tetromino.hpp"
#include "../game/Matrix.hpp"

class GameScene
    : public State
{
public:
    GameScene(StateManager& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);

    std::string         getHumanTime(sf::Time dt) const;

private: 
    Label			        mPlayerText;
    Label			        mScoreText;
    Label			        mNextText;
    sf::RectangleShape      mNextRec;
    Background              mBackground;
    Grid                    mGrid;
    sf::Time                timeSinceLastUpdate;
    sf::Time                timeLevel;
    Matrix                  mMatrix;
    Tetromino*              mTetromino;
    bool                    mPlayGame;
    void descend();
    void handlerCollisionEvent(CollisionDirection cd);
};

#endif
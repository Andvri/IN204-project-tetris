#ifndef GAMESCENE_CLASS
#define GAMESCENE_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"

class GameScene
    : public State
{
public:
    GameScene(StateManager& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);

private: 
    Label			        mPlayerText;
    Label			        mScoreText;
    Label			        mNextText;
    sf::RectangleShape      mNextRec;
    Background              mBackground;
    
};

#endif
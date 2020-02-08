#ifndef GAMESCENE_CLASS
#define GAMESCENE_CLASS

#include "../utils/States.hpp"
#include "SFML/Graphics.hpp"

class GameScene
    : public State
{
public:

    GameScene(StateManager& stack, Context context);
    ~GameScene();

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
private: 
    sf::CircleShape			mCircle;
};

#endif
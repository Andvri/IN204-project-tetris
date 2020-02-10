#ifndef GAMESCENE_CLASS
#define GAMESCENE_CLASS

#include "../utils/States.hpp"
#include "SFML/Graphics.hpp"
#include "../utils/Components/Grid.hpp"

class GameScene
    : public State
{
public:

    GameScene(StateManager& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
private: 
    Grid			    mGrid;
};

#endif
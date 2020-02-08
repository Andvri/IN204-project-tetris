#ifndef MENUSCENE_CLASS
#define MENUSCENE_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"


class MenuScene
    : public State
{
private:
    /* data */
public:
    MenuScene(StateManager& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
private: 
    sf::RectangleShape			mRectangle;
};

#endif
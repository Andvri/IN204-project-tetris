#ifndef MENUSCENE_CLASS
#define MENUSCENE_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Button.hpp"


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
    Background                  mBackground;
    Button                      mButton;
    Button                      mButton2;
    int                         mButtonSelect;
};

#endif
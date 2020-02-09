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
    std::vector<std::string> ButtonsLabel = { "Singleplayer",    "Multiplayer", "Exit" };

    void moveFocus(bool asc);
public:
    MenuScene(StateManager& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
private: 
    sf::RectangleShape			mRectangle;
    Background                  mBackground;
    std::vector<Button*>        mButtons;
    int                         mButtonSelect;

};

#endif
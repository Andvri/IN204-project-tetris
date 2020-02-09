#ifndef MULTIPLAYER_CLASS
#define MULTIPLAYER_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Button.hpp"


class MultiplayerScene
    : public State
{
private:
        std::vector<std::string> ButtonsLabel = { "Create", "Join", "Return" };

    void moveFocus(bool asc);
public:
    MultiplayerScene(StateManager& stack, Context context);

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);

private:
    Label                           mMultiplayerTitle;
    Background                      mBackground;
    std::vector<Button *>           mButtons;
    int                             mButtonChoice;
};

#endif
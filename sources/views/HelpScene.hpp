#ifndef HELPCLASS
#define HELPCLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Button.hpp"

class HelpScene
    : public State
{
private:
    std::vector<std::string>     mTextsLeft = {"Up:", "Down:", "Left/Right", "P:"};
    std::vector<std::string>     mTextsRight = {"Rotation", "Speed Up", "Move Left/Right", "Pause Menu"};
public:
    HelpScene(StateManager& stack, Context context);


    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);

private:
    Label                   mTitleHelp;
    Label                   mSubTitleButton;
    Label                   mSubTitleText;
    Button                  mReturn;
    std::vector<Label*>     mMsgButtons;
    std::vector<Label*>     mMsgExplain;
    Background              mBackground;  
};
#endif
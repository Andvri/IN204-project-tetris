#ifndef HELPCLASS
#define HELPCLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Button.hpp"

/**
 * @brief responsible for viewing the help page of the game
 * 
 */
class HelpScene
    : public State
{
private:
    std::vector<std::string>     mTextsLeft = {"Up:", "Down:", "Left/Right", "P:"};
    std::vector<std::string>     mTextsRight = {"Rotation", "Speed Up", "Move Left/Right", "Pause Menu"};
public:
    /**
     * @brief Construct a new Menu Scene object, standard builder
     * 
     * @param stack stack responsible for managing the views
     * @param context relates all current context
     */
    HelpScene(StateManager& stack, Context context);

/**
     * @brief overwriting the function drawing by adding new elements
     * responsible for sampling new elements added to this view
     */
    virtual void		draw();

    /**
     * @brief overwriting the function update by adding new elements
     * responsible for sampling new elements added to this view
     * @param dt Fraction of time
     * @return true 
     * @return false if have a problem
     */
    virtual bool		update(sf::Time dt);
    
    /**
     * @brief Adds new features to the function responsible for handling the events, adding a specific function for each key depending on the view
     * 
     * @param event getted action
     * @return true 
     * @return false if have a problem
     */
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
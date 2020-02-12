#ifndef MENUSCENE_CLASS
#define MENUSCENE_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Button.hpp"
#include "../utils/Components/Label.hpp"

/**
 * @brief responsible for viewing the game's main menu 
 * 
 */
class MenuScene
    : public State
{
private:
    std::vector<std::string> ButtonsLabel = { "Singleplayer", "Multiplayer", "Help", "Exit" };

    /**
     * @brief Switches the focus of the selected button
     * 
     * @param asc variable of control; true for active
     */
    void moveFocus(bool asc);
public:
    /**
     * @brief Construct a new Menu Scene object, standard builder
     * 
     * @param stack stack responsible for managing the views
     * @param context relates all current context
     */
    MenuScene(StateManager& stack, Context context);
    
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
    Label                       mMenuTitle;
    sf::RectangleShape			mRectangle;
    Background                  mBackground;
    std::vector<Button*>        mButtons;
    int                         mButtonSelect;

};

#endif
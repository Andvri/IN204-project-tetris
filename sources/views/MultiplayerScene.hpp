#ifndef MULTIPLAYER_CLASS
#define MULTIPLAYER_CLASS

#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"
#include "../utils/Components/Button.hpp"

/**
 * @brief class responsible for taking care of the introduction Multiplayer screen of the game
 * 
 */
class MultiplayerScene
    : public State
{
private:
    std::vector<std::string> ButtonsLabel = { "Create", "Join", "Return" };

    /**
     * @brief Switches the focus of the selected button
     * 
     * @param asc variable of control; true for active
     */
    void moveFocus(bool asc);
public:
    /**
     * @brief Construct a new Multiplayer Scene object, standard builder
     * 
     * @param stack stack responsible for managing the views
     * @param context relates all current context
     */
    MultiplayerScene(StateManager& stack, Context context);

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
    Label                           mMultiplayerTitle;
    Background                      mBackground;
    std::vector<Button *>           mButtons;
    int                             mButtonChoice;
    sf::Thread                      *th;
    bool                            waitResponse;
    Label                           waitMessage;
};

#endif
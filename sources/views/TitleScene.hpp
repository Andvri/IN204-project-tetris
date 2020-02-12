#ifndef TITLESCENE_CLASS
#define TITLESCENE_CLASS
#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"

/**
 * @brief class responsible for taking care of the initial screen of the game
 * 
 */
class TitleScene
    : public State
{
private:
    /* data */
public:
    /**
     * @brief Construct a new Title Scene object, standard builder
     * 
     * @param stack stack responsible for managing the views
     * @param context relates all current context
     */
    TitleScene(StateManager& stack, Context context);

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
    Label           mTitle;
    Label           mMsg;
    Label           mCopy;
    Background      mBackground;
};





#endif
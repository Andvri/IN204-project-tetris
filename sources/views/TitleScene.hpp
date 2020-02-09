#ifndef TITLESCENE_CLASS
#define TITLESCENE_CLASS
#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"
#include "../utils/Components/Label.hpp"
#include "../utils/Components/Background.hpp"
class TitleScene
    : public State
{
private:
    /* data */
public:
    TitleScene(StateManager& stack, Context context);


    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
private: 
    Label           mTitle;
    Label           mMsg;
    Label           mCopy;
    Background      mBackground;
};





#endif
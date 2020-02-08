#ifndef TITLESCENE_CLASS
#define TITLESCENE_CLASS
#include "SFML/Graphics.hpp"
#include "../utils/States.hpp"

class TitleScene
    : public State
{
private:
    /* data */
public:
    TitleScene(StateManager& stack, Context context);
    ~TitleScene();

    virtual void		draw();
    virtual bool		update(sf::Time dt);
    virtual bool		handleEvent(const sf::Event& event);
private: 
    sf::RectangleShape			mRectangle;
};





#endif
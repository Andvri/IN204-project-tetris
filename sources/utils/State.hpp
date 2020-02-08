#ifndef STATE_CLASS
#define STATE_CLASS

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

namespace sf
{
	class RenderWindow;
}

class StateStack;
class Player;


class State
{   
    public:
        struct Context
        {
            Context(sf::RenderWindow& window, Player& player);

            sf::RenderWindow*	window; 
            Player*				player;
        };

        State(StateStack& stack, Context context);
        virtual				~State();
        virtual void		draw() = 0;
        virtual bool		update(sf::Time dt) = 0;
        virtual bool		handleEvent(const sf::Event& event) = 0;
    protected:
        Context				getContext() const;

    private:
        StateStack*			mStack;
        Context				mContext;
};

#endif 
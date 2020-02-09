#ifndef STATE_CLASS
#define STATE_CLASS

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include "StateIdentifiers.hpp"

namespace sf
{
	class RenderWindow;
}

class StateManager;



class State
{   
    public:
        typedef std::unique_ptr<State> Ptr;
        struct Context
        {
            Context(sf::RenderWindow& window);
            sf::RenderWindow*	window;
        };

        State(StateManager& stack, Context context);
        virtual				~State();
        virtual void		draw() = 0;
        virtual bool		update(sf::Time dt) = 0;
        virtual bool		handleEvent(const sf::Event& event) = 0;
    protected:
        Context				getContext() const;

        void				requestStackPush(States::ID stateID);
		void				requestStackPop();
		void				requestStateClear();

    private:
        StateManager*		mStack;
        Context				mContext;
};

#endif 
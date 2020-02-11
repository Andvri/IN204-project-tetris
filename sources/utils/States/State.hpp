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

        /**
         * @brief structure that references the current context screen
         * 
         */
        struct Context
        {
            Context(sf::RenderWindow& window);
            sf::RenderWindow*	window;
        };

        /**
         * @brief Construct a new State object
         * 
         * @param stack Stack of views
         * @param context Relative Window
         */
        State(StateManager& stack, Context context);
        virtual				~State();

        /**
         * @brief Performs the removal of each view from the top of the stack and draws them
         * 
         */
        virtual void		draw() = 0;

        /**
         * @brief Controls shine and highlight effects
         * 
         * @param dt refresh time linked to fps
         * @return true 
         * @return false if have a problem
         */
        virtual bool		update(sf::Time dt) = 0;

        /**
         * @brief responsible for calling events on the screen, which serves as the basis for all input handling
         * 
         * @param event 
         * @return true by default
         */
        virtual bool		handleEvent(const sf::Event& event) = 0;
    protected:

        /**
         * @brief Get the Context object, view
         * 
         * @return Context 
         */
        Context				getContext() const;

        /**
         * @brief Sends for treatment the selected view that was allocated
         * 
         * @param stateID 
         */
        void				requestStackPush(States::ID stateID);

        /**
         * @brief Removal from storage of initiated views
         * 
         */
		void				requestStackPop();

        /**
         * @brief clean the stack views order
         * 
         */
		void				requestStateClear();

    private:
        StateManager*		mStack;
        Context				mContext;
};

#endif 
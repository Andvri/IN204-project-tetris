#ifndef CLASS_APPLICATION
#define CLASS_APPLICATION

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "./utils/States.hpp"

/**
 * @brief Responsible for all initialization of the project
 * 
 */
class Application
{
    public:
        /**
         * @brief Initialize the screen default size and the "state manager", Inserting in the stack at first view: the Title
         * 
         */
                Application();
                ~Application();

        /**
        * @brief Responsible for starting the game and calling functions that generate it
        * 
        */
        void	run();

    private:
        /**
         * @brief Responsable for the validation of the screen events
         * 
         */
        void	processInput();

        /**
         * @brief Used to carry on things, e.g. effects
         * 
         * @param dt Update rate of these functions (as fps)
         */
        void	update(sf::Time dt);
        /**
         * @brief Updates things drawn on the screen, and manages views
         * 
         */
        void    render();
        /**
         * @brief Put the states inside the stack.
         * 
         */
        void    registerStates();

    private:
        /**
         * @brief Fixed fps value
         * 
         */
        static const sf::Time	TimePerFrame;

        /**
         * @brief window variable
         * 
         */
        sf::RenderWindow		mWindow;

        /**
         * @brief stack
         * 
         */
        StateManager		    mStateStack;
};
#endif
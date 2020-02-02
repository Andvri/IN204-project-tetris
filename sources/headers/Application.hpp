#ifndef APPLICATION_CLASS
#define APPLICATION_CLASS

#include "../../utils/headers/ResourceHolder.hpp"
#include "../../utils/headers/ResourceIdentifiers.hpp"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "./Tetris.hpp"

class Application
{
	public:
								Application();
                                ~Application();
		void					run();
		

    private:
        void					processInput();
		void					update(sf::Time dt);
		void					render();
		void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
        Tetris					mTetris;

        sf::Text                mTitle;
	  	sf::Font				mFont;
};
#endif
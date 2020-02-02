#ifndef APPLICATION_CLASS
#define APPLICATION_CLASS

#include "../../utils/headers/ResourceHolder.hpp"
#include "../../utils/headers/ResourceIdentifiers.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

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

	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
        sf::Sprite		mBackgroundSprite;
        sf::Text                mTitle;
        TextureHolder			mTextures;
	  	FontHolder				mFonts;
};
#endif
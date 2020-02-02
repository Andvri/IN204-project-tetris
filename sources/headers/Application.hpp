#ifndef APPLICATION_CLASS
#define APPLICATION_CLASS

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

		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};
#endif
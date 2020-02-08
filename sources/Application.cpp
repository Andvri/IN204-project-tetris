#include "./Application.hpp"

const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application():
    mWindow(sf::VideoMode(1024, 576), "TETRIS 20.20")
{}

Application::~Application()
{}

void Application::run ()
{
    sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processInput();
			update(TimePerFrame);
			/**
			 * 	
			 *	if (StateManager.isEmpty())
				mWindow.close(); 
			 */
		}

		render();
	}
}

void Application::processInput()
{

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		//StateManager  handleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}

}

void Application::update(sf::Time dt)
{
	// StateManager update(dt);
}

void Application::render()
{
	mWindow.clear();

	//StateManager  draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}

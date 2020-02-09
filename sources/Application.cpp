#include "./Application.hpp"
#include "./Views.hpp"


const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application():
    mWindow(sf::VideoMode(1920, 1080), "TETRIS 20.20"), 
	mStateStack( State::Context(mWindow) )
{
	registerStates();
	mStateStack.pushState(States::Title);
}

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
			
			if (mStateStack.isEmpty())
				mWindow.close();
		}

		render();
	}
}

void Application::processInput()
{

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mStateStack.handleEvent(event);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}

}

void Application::update(sf::Time dt)
{
	mStateStack.update(dt);
}

void Application::render()
{
	mWindow.clear();

	mStateStack.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.display();
}


void Application::registerStates()
{
	mStateStack.registerState<TitleScene>(States::Title);
	mStateStack.registerState<MenuScene>(States::Menu);
	mStateStack.registerState<GameScene>(States::Game);
}
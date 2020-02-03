#include "./headers/Application.hpp"
#include <iostream>
const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application():
    mWindow(sf::VideoMode(1024, 576), "TETRIS 20.20"),
    mTetris(mWindow), 
	mPlayer(),
	mFont()
{
    //mFont.loadFromFile("media/fonts/Blank-Regular.otf");
	//mTitle.setFont(mFont);
	//mTitle.setString("TETRIS 2020");
	//mTitle.setPosition(sf::Vector2f(300, 180));
	//mTitle.setCharacterSize(80); // in pixels, not points!
	//mTitle.setFillColor(sf::Color::White);
}

Application::~Application()
{
}

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

		}

		render();
	}
}

void Application::processInput()
{
	CommandQueue& commands = mTetris.getCommandQueue();

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mPlayer.handleEvent(event, commands);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}

	mPlayer.handleRealtimeInput(commands);
}

void Application::update(sf::Time dt)
{
	mTetris.update(dt);
}

void Application::render()
{
	mWindow.clear();
	mTetris.draw();

	mWindow.setView(mWindow.getDefaultView());
//	mWindow.draw(mTitle);
	mWindow.display();
}

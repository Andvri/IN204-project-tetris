#include "./headers/Application.hpp"
#include <iostream>
const sf::Time Application::TimePerFrame = sf::seconds(1.f/60.f);

Application::Application():
    mWindow(sf::VideoMode(1024, 576), "TETRIS 20.20"),
    mTextures(), 
    mFonts(),
	mBackgroundSprite()
{
    mFonts.load(Fonts::Anurati, "media/fonts/Anurati-Regular.otf");
    mFonts.load(Fonts::Blanka, "media/fonts/Blanka-Regular.otf");
	mTextures.load(Textures::DefaultBackground, "media/images/Galaxy2.png");

    mTextures.get(Textures::DefaultBackground).setRepeated(true);
    mBackgroundSprite.setTexture(mTextures.get(Textures::DefaultBackground));	
	mBackgroundSprite.setTextureRect(sf::IntRect(0, 0, mWindow.getSize().x,mWindow.getSize().y));
	mTitle.setFont(mFonts.get(Fonts::Blanka));
	mTitle.setString("TETRIS 2020");
	mTitle.setPosition(sf::Vector2f(300, 180));
	mTitle.setCharacterSize(80); // in pixels, not points!


	mTitle.setFillColor(sf::Color::White);
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
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();

        if (event.type == sf::Event::Resized)
		{
			// update the view to the new size of the window

			mBackgroundSprite.setTextureRect(sf::IntRect(0, 0, event.size.width, event.size.height));

			// update the view to the new size of the window
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);

			std::cout << event.size.width << "-"<< event.size.height << std::endl;
			mWindow.setView(sf::View(visibleArea));

			std::cout << event.size.width << "-"<< event.size.height << std::endl;
		}
	}
}

void Application::update(sf::Time dt)
{
	
}

void Application::render()
{
	mWindow.clear();
    mWindow.draw(mBackgroundSprite);
	mWindow.draw(mTitle);
	mWindow.display();
}

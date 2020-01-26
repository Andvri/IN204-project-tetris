#include "./headers/game.hpp"

Game::Game()
    : mWindow(sf::VideoMode(640, 480), "TETRIS")
    , mPlayer()
    , show(true)
{
    mPlayer.getFigure().setSize(sf::Vector2f(40,40));
    mPlayer.getFigure().setPosition(100.f, 100.f);
    mPlayer.getFigure().setFillColor(sf::Color::Red);
}


void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}


void Game::processEvents() 
{

    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
            break;
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
            break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    int PlayerSpeed = 100;
    sf::Vector2f movement(0.f, 0.f);
    if (mIsMovingUp)
    movement.y -= PlayerSpeed;
    if (mIsMovingDown)
    movement.y += PlayerSpeed;
    if (mIsMovingLeft)
    movement.x -= PlayerSpeed;
    if (mIsMovingRight)
    movement.x += PlayerSpeed;
    mPlayer.getFigure().move(movement * deltaTime.asSeconds());
    mPlayer.getFigure().rotate(45);
}

void Game::render()
{
    mWindow.clear();
    if (show) {
        mWindow.draw(mPlayer.getFigure());
    }
    mWindow.display();    
}


void Game::handlePlayerInput(sf::Keyboard::Key key,
bool isPressed)
{
    if (key == sf::Keyboard::W)
    mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
    mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
    else
    {
        show = !show;
    }
    
}
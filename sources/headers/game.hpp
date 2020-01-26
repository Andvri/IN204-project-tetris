#include "./square.hpp"
#ifndef GAME_CLASS
#define GAME_CLASS
#include "SFML/Graphics.hpp"
class Game
{
    private:
        sf::RenderWindow mWindow;
        Square mPlayer;
        sf::RectangleShape mPlayer2;
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        
        bool mIsMovingUp;
        bool mIsMovingDown;
        bool mIsMovingLeft;
        bool mIsMovingRight;
        bool show;
        
    public:
        Game();
        void run();
};
#endif

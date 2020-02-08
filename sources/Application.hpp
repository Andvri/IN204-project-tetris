#ifndef CLASS_APPLICATION
#define CLASS_APPLICATION

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Application
{
    public:
                Application();
                ~Application();
        void	run();
    private:
        void	processInput();
        void	update(sf::Time dt);
        void    render();

    private:
        static const sf::Time	TimePerFrame;
        sf::RenderWindow		mWindow;
};
#endif
#include <SFML/Graphics.hpp>
#include "libraries.hpp"

void teste(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

}

    //Parei em comecar a criar a funcao da tabela e preencher com as peças
int main()
{
    teste();
    return 0;
}
#include <SFML/Graphics.hpp>
#include "src/headers/board.hpp"
#include "src/headers/color.hpp"
#include "src/headers/fiches.hpp"
#include "src/headers/figure.hpp"
#include "src/headers/program.hpp"
#include "src/headers/shape.hpp"

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
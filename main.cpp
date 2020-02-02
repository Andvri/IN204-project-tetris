#include "./libraries.hpp"

    //Global Veriables
Figure tetrino;
Board table;
const sf::Color colors[] = {
    sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::White, sf::Color::Magenta, sf::Color::Cyan
};
bool check = false, checkTimer = true; //---> created for trying stop bugs
sf::Clock timer;
Player player1;

void gameBody(sf::Clock timer, bool check, Board table, Figure tetrino, const sf::Color colors[], bool checkTimer, Player& player);

int main()
{
    gameBody(timer, check, table, tetrino, colors, checkTimer, player1);
    return 0;
}
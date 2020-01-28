#include "./libraries.hpp"

Figure tetrino;
Board table;
const sf::Color colors[] = {
    sf::Color::Green, sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::White, sf::Color::Magenta, sf::Color::Cyan
};

void design(){
    sf::RenderWindow window(sf::VideoMode(LARGUEUR*BLOCKSIZE, HAUTER*BLOCKSIZE), "TETRIS");
    sf::RectangleShape block(sf::Vector2f(BLOCKSIZE, BLOCKSIZE));

    auto movDown = [&](){
        tetrino.posY++;
        if (table.checkLimits(tetrino) == false){
            tetrino.posY--;
            for (int y = 0; y < 4; y++){
                for (int x = 0; x < 4; x++){
                    if (tetrino.form[tetrino.kind][y][x]){
                        table.tableau[tetrino.posY + y][tetrino.posX + x] = tetrino.kind + 1;
                    }
                }
            }
            table.clearLines();
            tetrino.newBlock();
        };
    };

    tetrino.newBlock();
    sf::Clock timer;
    while (window.isOpen())
    {
        static float prev = timer.getElapsedTime().asSeconds();
        if (timer.getElapsedTime().asSeconds() - prev >= 0.5){
            prev = timer.getElapsedTime().asSeconds();
            movDown();
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)  window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Left){
                    tetrino.posX--;
                    if (table.checkLimits(tetrino) == false) tetrino.posX++;
                }if (event.key.code == sf::Keyboard::Right){
                    tetrino.posX++;    
                    if (table.checkLimits(tetrino) == false) tetrino.posX--;
                }if (event.key.code == sf::Keyboard::Down){
                    movDown();
                }if(event.key.code == sf::Keyboard::Up){
                    tetrino.rotate();
                }
            }
        }

        window.clear();

        auto build = [&](){
            for (int y = 0; y < HAUTER; y++){
                for (int x = 0; x < LARGUEUR; x++){
                    block.setFillColor(colors[table.tableau[y][x] - 1]);
                    block.setPosition(sf::Vector2f(x*BLOCKSIZE, y*BLOCKSIZE));
                    window.draw(block);
                }
            }
        };
        build();


        auto draw_blck = [&](){
            block.setFillColor(colors[tetrino.kind]);
            for (int y = 0; y < 4; y++){
                for (int x = 0; x < 4; x++){
                    if (tetrino.form[tetrino.kind][y][x]){
                        block.setPosition(sf::Vector2f((tetrino.posX + x)*BLOCKSIZE, (tetrino.posY + y)*BLOCKSIZE));
                        window.draw(block);
                    }
                }
            }
        };

        draw_blck(); 
        window.display();
    }

}

int main()
{
    design();
    return 0;
}
#include "SFML/Graphics.hpp"
#include "./headers/board.hpp"
#include "./headers/figure.hpp"




inline void gameBody(sf::Clock timer, bool check, Board table, Figure tetrino, const sf::Color colors[], bool checkTimer, Player& player){
    sf::RenderWindow window(sf::VideoMode(LARGUEUR*BLOCKSIZE, HAUTER*BLOCKSIZE), "TETRIS");
    sf::RectangleShape block(sf::Vector2f(BLOCKSIZE, BLOCKSIZE));

    auto movDown = [&](){
        tetrino.addPosY(1);
        if (table.checkLimits(tetrino) == false){
            tetrino.addPosY(-1);
            for (int y = 0; y < 4; y++){
                for (int x = 0; x < 4; x++){
                    if (tetrino.getPontualForm(y, x)){
                        table.setPontualPoint(tetrino.getPosY() + y, tetrino.getPosX() + x, tetrino.getKind() + 1);
                    }
                }
            }
            table.clearLines(player);
            tetrino.newBlock();
        };
    };

    tetrino.newBlock();
    float delay = 0.3;
    while (window.isOpen())
    {
        if (checkTimer){

            if (player.levelUp){
                delay -= 0.03;
                player.levelUp = false;
            }
            
            static float prev = timer.getElapsedTime().asSeconds();
            if (timer.getElapsedTime().asSeconds() - prev >= delay){
                prev = timer.getElapsedTime().asSeconds();
                movDown();
            }
        }
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)  window.close();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Left){
                    tetrino.addPosX(-1);
                    if (table.checkLimits(tetrino) == false) tetrino.addPosX(1);
                }if (event.key.code == sf::Keyboard::Right){
                    tetrino.addPosX(1);    
                    if (table.checkLimits(tetrino) == false) tetrino.addPosX(-1);
                }if (event.key.code == sf::Keyboard::Down){
                    movDown();
                }if(event.key.code == sf::Keyboard::Up){
                    check = true;
                    tetrino.rotate();
                    check = false;
                }if(event.key.code == sf::Keyboard::P){
                    checkTimer = !checkTimer;
                }
            }
        }

        window.clear();

        auto drawWorld = [&](){
            
            if (!check){
                for (int y = 0; y < HAUTER; y++){
                    for (int x = 0; x < LARGUEUR; x++){
                        if (table.getPontualPoint(y, x)){
                            block.setFillColor(colors[table.getPontualPoint(y, x) - 1]);
                            block.setOutlineThickness(1.0f);
                            block.setOutlineColor(sf::Color::Black);
                        }else{
                            block.setFillColor(sf::Color(192, 192, 192, 255));
                            block.setOutlineThickness(1.0f);
                            block.setOutlineColor(sf::Color::Black);
                        }
                        
                        block.setPosition(sf::Vector2f(x*BLOCKSIZE, y*BLOCKSIZE));
                        window.draw(block);
                    }
                }
            }
        };
        drawWorld();


        auto drawBlocks = [&](){
            if (!check){
                block.setFillColor(colors[tetrino.getKind()]);
                for (int y = 0; y < 4; y++){
                    for (int x = 0; x < 4; x++){
                        if (tetrino.getPontualForm(y, x)){
                            block.setOutlineThickness(1.0f);
                            block.setOutlineColor(sf::Color::Black);
                            block.setPosition(sf::Vector2f((tetrino.getPosX() + x)*BLOCKSIZE, (tetrino.getPosY() + y)*BLOCKSIZE));
                            window.draw(block);
                        }
                    }
                }
            }
        };

        drawBlocks(); 
        window.display();
    }

}

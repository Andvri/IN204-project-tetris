### INSTALATION
* Program used for Linux, test version Ubuntu 18.04
* [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) installation required to run the game


### Guide: How to compile
We just need to follow these steps to compile the program:

sh
$ make
$ ./build/program


# Useful information for Alone Compilation
    g++ -c -o nameoutput main.cpp
    g++ nameoutput -o autrename -lsfml-graphics -lsfml-window -lsfml-system  --> lien entre les deux archives

    Ou

    g++ file.cpp -o quelquenom lsfml-graphics -lsfml-window -lsfml-system  --> Direct

## Repository GitLab

https://gitlab.data-ensta.fr/martinez-boada/in204-project
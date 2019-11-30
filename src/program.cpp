#include "headers/program.hpp"

Program::Program () {
    this->n = 100;
}

void Program::start () {
    std::cout << this->n << std::endl;
}
#include "sources/Application.hpp"
#include "sources/game/Tetromino.hpp"
#include "sources/game/Matrix.hpp"
#include "sources/game/Z.hpp"
#include <iostream>
#include <stdexcept>
int main()
{
    try
	{
         Matrix m(5,5);
		 std::cout << m.codePosition(4,3) << std::endl;
		 std::cout << m.decodePosition(11).x << "," << m.decodePosition(11).y << std::endl;
		 

	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
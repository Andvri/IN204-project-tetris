#include "sources/Application.hpp"
#include "sources/game/Tetromino.hpp"
#include "sources/game/Matrix.hpp"
#include <iostream>
#include <stdexcept>
int main()
{
    try
	{
         Tetromino a(AvailableColors::BLUE);
		 Tetromino b(AvailableColors::BLUE);
		 Matrix m;
         if (a == m) {
			 std::cout << "a = m" << std::endl;
		 }
		 if (b == m)
		 {
			 std::cout << "b = m" << std::endl;
		 }

	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
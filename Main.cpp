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
          Tetromino a(20,10);
		  a.print();
		  a = a+1;
		  a.print();
		  a--;
		  a.print();
		  a--;
		  a = a+3;
		  a.print();
		  a--;
		  a.print();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
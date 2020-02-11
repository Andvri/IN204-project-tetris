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
          Tetromino a(10,10);
		  Matrix m(10,10);
		  std::cout << m + a << std::endl;
		  a++;
		  std::cout << m + a << std::endl;
		  a++;
		  std::cout << m + a << std::endl;
		  a = a+1;
		  std::cout << m + a << std::endl;
		  a = a++;
		  std::cout << m + a << std::endl;
		  a = a++;
		  std::cout << m + a << std::endl;


	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
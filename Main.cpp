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
		  a.print();
		  
		  Matrix m(10, 20);
		  m = (m+a);
          Tetromino b = a+1;
		  b++;
		  m = (m+b);
		  std::cout << m << std::endl;


	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
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
         Tetromino a(AvailableColors::BLUE);
		 Tetromino b(AvailableColors::BLUE);
		 Z z;
		 Z *zz= new Z();
		 Matrix m;
		 a.rotate();
		 a.rotate(Direction::COUNTERCLOCKWISE);
		 z.rotate();
		 zz->print();
		 (*zz)++;
		 zz->print();
         if (a == m) {
			 std::cout << "a = m" << std::endl;
		 }
		 if (!(m == z))
		 {
			 std::cout << "m != z" << std::endl;
		 }

		 if (!(z == m))
		 {
			 std::cout << "z != m" << std::endl;
		 }

	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
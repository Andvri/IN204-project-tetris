/**
 *  IN-204 Project TETRIS
 *  main.cpp
 *  Purpose: Principal function. Run the program
 *
 *  @author Javier Martinez
 *  @email javier-andres.martinez-boada@ensta-paris.fr
 * 	@author Fabricio Vellone
 * 	@email fabricio.vellone@ensta-paris.fr 
 *  @version 1.07 09/02/2020
 */

#include "sources/Application.hpp"
#include <iostream>
#include <stdexcept>
/**
 *  @brief  Global function named main, which is the designated start of the program
 *
 *  @return int             Shows how the program exited. The normal exit of program is 
 *                          represented by zero return value. If the code has errors, 
 *                          fault etc., it will be terminated by non-zero value
 */
int main()
{
    try
	{
		Application app;
		app.run();
	}
	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
        return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}
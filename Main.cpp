#include "sources/Application.hpp"
#include <iostream>
#include <stdexcept>
#include<ctime>
#include<cstdlib>
int main()
{
	
    try
	{
		srand(time(NULL));
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
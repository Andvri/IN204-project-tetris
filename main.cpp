/**
 *  IN-204 Project TETRIS
 *  main.cpp
 *  Purpose: Principal function. Run the program
 *
 *  @author Javier Martinez
 *  @email javier-andres.martinez-boada@ensta-paris.fr
 *  @version 1.0 11/30/2019
 */
#include "libraries.hpp"
/**
 *  @brief  Global function named main, which is the designated start of the program
 *
 *  @param  int     argc 	Non-negative value representing the number of arguments passed
 *                          to the program from the environment in which the program is run.
 * 
 *  @param  char    *argv 	Pointer to the first element of an array of argc + 1 pointers,
 *                          of which the last one is null and the previous ones, if any, 
 *                          point to null-terminated multibyte strings that represent 
 *                          the arguments passed to the program from the execution environment.
 *
 *  @return int             Shows how the program exited. The normal exit of program is 
 *                          represented by zero return value. If the code has errors, 
 *                          fault etc., it will be terminated by non-zero value
 */
int main (int argc, char *argv[]) 
{
    Program *p = new Program();
    p->start();

    return EXIT_SUCCESS;
}
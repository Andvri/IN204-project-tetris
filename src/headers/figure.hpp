#ifndef FIGURE_CLASS
#define FIGURE_CLASS
#include <iostream>
#include "color.hpp"
#include "shape.hpp"

class Figure
{
public:
    Figure () {}
    Figure (Color color, Shape shape) 
        : color(color), shape(shape) {}
    void turnLeft();
    void turnRight();
protected:
    Color color;
    Shape shape;
};
#endif
#include <iostream>
#include "Line.h"
#include "Rectangle.h"

int main()
{
    Line line = Line(1, 2, 3, 4, "black");

    Rectangle rec = Rectangle(1,2,3,4, "green");

    std::cout << rec.getInfo();
}
#include "Circle.h"

Circle::Circle(double diameter, const Point& origin, const char* color)
	: Shape(origin, color)
{
	this->diameter = diameter;
}

double Circle::GetArea() const
{
	return 3.14f * diameter / 4;;
}

double Circle::GetParameter() const
{
	return 3.14f * diameter;
}

void Circle::Print() const
{
	std::cout << "Circle: \n";
	std::cout << "Origin: " << origin.X << " " << origin.Y << '\n';
	std::cout << "Color: " << color << '\n';
	std::cout << "Diameter: " << diameter << '\n';
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

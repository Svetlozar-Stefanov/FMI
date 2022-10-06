#include "Rhombus.h"

Rhombus::Rhombus(double len, double deg, const Point& origin, const char* color)
	: Shape(origin, color)
{
	this->len = len;
	this->deg = deg;
}

double Rhombus::GetArea() const
{
	return len * len *sin(deg);
}

double Rhombus::GetParameter() const
{
	return 4 * len;
}

void Rhombus::Print() const
{
	std::cout << "Rhombus: \n";
	std::cout << "Origin: " << origin.X << " " << origin.Y << '\n';
	std::cout << "Color: " << color << '\n';
	std::cout << "Side: " << len << '\n';
}

Shape* Rhombus::clone() const
{
	return new Rhombus(*this);
}

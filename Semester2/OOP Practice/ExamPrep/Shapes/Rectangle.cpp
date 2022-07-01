#include "Rectangle.h"

Rectangle::Rectangle(double lenA, double lenB, const Point& origin, const char* color)
	: Shape(origin, color)
{
	this->lenA = lenA;
	this->lenB = lenB;
}

double Rectangle::GetArea() const
{
	return lenA * lenB;
}

double Rectangle::GetParameter() const
{
	return 2 * (lenA + lenB);
}

void Rectangle::Print() const
{
	std::cout << "Rectangle: \n";
	std::cout << "Origin: " << origin.X << " " << origin.Y << '\n';
	std::cout << "Color: " << color << '\n';
	std::cout << "Sides: " << lenA << lenB << '\n';
}

Shape* Rectangle::clone() const
{
	return new Rectangle(*this);
}

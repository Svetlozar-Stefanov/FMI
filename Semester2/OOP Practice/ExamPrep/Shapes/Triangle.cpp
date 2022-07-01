#include "Triangle.h"

Triangle::Triangle(double lenA, double lenB, double lenC,
	double degAB, double degAC, double degBC,
	const Point& origin, const char* color)
	: Shape(origin, color)
{
	this->lenA = lenA;
	this->lenB = lenB;
	this->lenC = lenC;

	this->degAB = degAB;
	this->degAC = degAC;
	this->degBC = degBC;
}

double Triangle::GetArea() const
{
	return (1 / 2 * lenA * lenB * sin(degAB));
}

double Triangle::GetParameter() const
{
	return lenA + lenB + lenC;
}

void Triangle::Print() const
{
	std::cout << "Triangle: \n";
	std::cout << "Origin: " << origin.X << " " << origin.Y << '\n';
	std::cout << "Color: " << color << '\n';
	std::cout << "Sides: " << lenA << " " << lenB << " " << lenC << '\n';
}

Shape* Triangle::clone() const
{
	return new Triangle(*this);
}

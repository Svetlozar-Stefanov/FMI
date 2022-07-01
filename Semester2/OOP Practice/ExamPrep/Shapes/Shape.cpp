#include "Shape.h"

void Shape::copy(const Shape& other)
{
	origin = other.origin;
	color = new char[strlen(other.color)];
	strcpy(color, other.color);
}

void Shape::free()
{
	delete[] color;
}

Shape::Shape(const Point& origin, const char* color)
{
	this->origin = origin;
	this->color = new char[strlen(color)];
	strcpy(this->color, color);
}

Shape::Shape(const Shape& other)
{
	copy(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Shape::~Shape()
{
	free();
}

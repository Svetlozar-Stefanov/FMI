#include "Point.h"

Point::Point(const int x, const int y)
{
	SetX(x);
	SetY(y);
}

void Point::SetX(const int x)
{
	this->x = x;
}

void Point::SetY(const int y)
{
	this->y = y;
}

const int Point::GetX() const
{
	return x;
}

const int Point::GetY() const
{
	return y;
}

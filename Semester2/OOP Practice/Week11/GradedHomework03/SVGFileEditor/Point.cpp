#include "Point.h"

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

Point::Point(const float x, const float y)
{
	SetX(x);
	SetY(y);
}

void Point::SetX(const float x)
{
	this->x = x;
}

void Point::SetY(const float y)
{
	this->y = y;
}

const float Point::GetX() const
{
	return x;
}

const float Point::GetY() const
{
	return y;
}

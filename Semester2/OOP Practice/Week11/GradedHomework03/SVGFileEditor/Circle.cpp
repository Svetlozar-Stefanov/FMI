#include "Circle.h"

Circle::Circle(const int x, const int y, const int r, const svgString& fill)
	: origin(x, y), SVGElement(fill)
{
	this->r = r;
}

svgString Circle::getInfo()
{
	svgString str;
	str += "circle x=";
	str += origin.GetX();
	str += " y=";
	str += origin.GetY();
	str += " radius=";
	str += r;
	str += " ";
	str += fill;

	return str;
}

void Circle::Translate(const float horiz, const float vert)
{
	int newX = origin.GetX() + horiz;
	int newY = origin.GetY() + vert;

	origin.SetX(newX);
	origin.SetY(newY);
}

bool Circle::isWithinRegion()
{
	return false;
}

bool Circle::ContainsPoint(const int x, const int y)
{
	float distance = sqrt((origin.GetX() - x) * (origin.GetX() - x) + (origin.GetY() - y) * (origin.GetY() - y));
	if (distance > r)
	{
		return false;
	}

	return true;
}

float Circle::GetArea()
{
	return PI * PI * r;
}

float Circle::GetPerimeter()
{
	return 2 * PI * r;
}

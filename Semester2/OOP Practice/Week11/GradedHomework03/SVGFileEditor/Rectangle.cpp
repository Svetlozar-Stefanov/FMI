#include "Rectangle.h"

Rectangle::Rectangle(const int x, const int y, const int width, const int height, const svgString& fill)
	: origin(x, y), SVGElement(fill)
{
	this->width = width;
	this->height = height;
}

svgString Rectangle::GetInfo()
{
	svgString str;
	str += "rectangle x=";
	str += origin.GetX();
	str += " y=";
	str += origin.GetY();
	str += " width=";
	str += width;
	str += " height=";
	str += height;
	str += " ";
	str += fill;

	return str;
}

void Rectangle::Translate(const float horiz, const float vert)
{
	int newX = origin.GetX() + horiz;
	int newY = origin.GetY() + vert;

	origin.SetX(newX);
	origin.SetY(newY);
}

bool Rectangle::IsWithinRegion(const int x, const int y, const int width, const int height)
{
	Rectangle rec(x, y, width, height, "");

	int x1 = origin.GetX();
	int x2 = origin.GetX() + width;

	int y1 = origin.GetY();
	int y2 = origin.GetY() + height;

	if (!(rec.ContainsPoint(x1, y1)
		&& rec.ContainsPoint(x2, y1)
		&& rec.ContainsPoint(x1, y2)
		&& rec.ContainsPoint(x2, y2)))
	{
		return false;
	}
	
	return true;
}

bool Rectangle::IsWithinRegion(const int x, const int y, const int r)
{
	int x1 = origin.GetX();
	int x2 = origin.GetX() + width;

	int y1 = origin.GetY();
	int y2 = origin.GetY() + height;

	float distance1 = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
	if (distance1 > r)
	{
		return false;
	}

	float distance2 = sqrt((x2 - x) * (x2 - x) + (y1 - y) * (y1 - y));
	if (distance2 > r)
	{
		return false;
	}

	float distance3 = sqrt((x1 - x) * (x1 - x) + (y2 - y) * (y2 - y));
	if (distance3 > r)
	{
		return false;
	}

	float distance4 = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	if (distance4 > r)
	{
		return false;
	}

	return true;
}

bool Rectangle::ContainsPoint(const int x, const int y)
{
	int x1 = origin.GetX();
	int x2 = origin.GetX() + width;

	int y1 = origin.GetY();
	int y2 = origin.GetY() + height;

	if (!(x < x1 && x > x2 || x < x2 && x > x1))
	{
		return false;
	}
	if (!(y < y1 && y > y2 || y < y2 && y > y2))
	{
		return false;
	}
}

float Rectangle::GetArea()
{
	return width * height;
}

float Rectangle::GetPerimeter()
{
	return 2 * width + 2 * height;
}

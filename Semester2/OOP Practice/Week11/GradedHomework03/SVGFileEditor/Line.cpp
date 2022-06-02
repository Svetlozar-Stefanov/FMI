#include "Line.h"

Line::Line(const float x1, const float y1,
		const float x2, const float y2,
		const svgString& fill)
	: SVGElement(fill), a(x1, y1), b(x2, y2)
{
}

svgString Line::GetInfo()
{
	svgString str;
	str += "line x1=";
	str += a.GetX();
	str += " y1=";
	str += a.GetY();
	str += " x2=";
	str += b.GetX();
	str += " y2=";
	str += b.GetY();
	str += " ";
	str += fill;
	
	return str;
}

void Line::Translate(const float horiz, const float vert)
{
	float newX1 = a.GetX() + horiz;
	float newX2 = b.GetX() + horiz;
	float newY1 = a.GetY() + vert;
	float newY2 = b.GetY() + vert;

	a.SetX(newX1);
	a.SetY(newY1);
	b.SetX(newX2);
	b.SetY(newY2);
}

bool Line::IsWithinRegion(const float x, const float y, const float width, const float height)
{
	int x1 = x;
	int x2 = x + width;
	int y1 = y;
	int y2 = y + height;

	if (!((a.GetX() >= x1 && a.GetX() <= x2)))
	{
		return false;
	}
	if (!((a.GetY() >= y1 && a.GetY() <= y2)))
	{
		return false;
	}

	if (!((b.GetX() >= x1 && b.GetX() <= x2)))
	{
		return false;
	}
	if (!((b.GetY() >= y1 && b.GetY() <= y2)))
	{
		return false;
	}

	return true;
}

bool Line::IsWithinRegion(const float x, const float y, const float r)
{
	float distance1 = sqrt((a.GetX() - x) * (a.GetX() - x) + (a.GetY() - y) * (a.GetY() - y));
	if (distance1 > r)
	{
		return false;
	}

	float distance2 = sqrt((b.GetX() - x) * (b.GetX() - x) + (b.GetY() - y) * (b.GetY() - y));
	if (distance2 > r)
	{
		return false;
	}

	return true;
}

bool Line::ContainsPoint(const float x, const float y)
{
	if (!((x >= a.GetX() && x <= b.GetX()) || (x >= b.GetX() && x <= a.GetX())))
	{
		return false;
	}
	if (!((y >= a.GetY() && y <= b.GetY()) || (y >= b.GetY() && y <= a.GetY())))
	{
		return false;
	}
	if (((a.GetX() - x) * (b.GetY() - y) - (a.GetY() - y) * (b.GetX() - x)) != 0)
	{
		return false;
	}

	return true;
}

float Line::GetArea()
{
	return sqrt((b.GetX() - a.GetX()) * (b.GetX() - a.GetX()) + (b.GetY() - a.GetY()) * (b.GetY() - a.GetY()));
}

float Line::GetPerimeter()
{
	return sqrt((b.GetX() - a.GetX()) * (b.GetX() - a.GetX()) + (b.GetY() - a.GetY()) * (b.GetY() - a.GetY()));
}

SVGElement* Line::clone() const
{
	return new Line(*this);
}

std::fstream& Line::operator<<(std::fstream& st)
{
	st << "<line " << "x1=\"" << a.GetX() << "\"" << " y1=\"" << a.GetY() << "\""
		<< " x2=\"" << b.GetX() << "\"" << " y2=\"" << b.GetY() << "\"" 
		<< " fill=\"" << fill << "\" />\n";

	return st;
}

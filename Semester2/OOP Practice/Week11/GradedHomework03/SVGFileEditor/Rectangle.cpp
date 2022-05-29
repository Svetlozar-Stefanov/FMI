#include "Rectangle.h"

Rectangle::Rectangle(const float x, const float y, const float width, const float height, const svgString& fill)
	: SVGElement(fill)
{
	float x1 = x;
	float x2 = x + width;

	float y1 = y;
	float y2 = y + height;

	p[0].SetX(x1);
	p[0].SetY(y1);

	p[1].SetX(x2);
	p[1].SetY(y1);

	p[2].SetX(x1);
	p[2].SetY(y2);

	p[3].SetX(x2);
	p[3].SetY(y2);

	this->width = width;
	this->height = height;
}

svgString Rectangle::GetInfo()
{
	svgString str;
	str += "rectangle x=";
	str += p[0].GetX();
	str += " y=";
	str += p[0].GetY();
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
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		p[i].SetX(p[i].GetX() + horiz);
		p[i].SetY(p[i].GetY() + vert);
	}
}

bool Rectangle::IsWithinRegion(const float x, const float y, const float width, const float height)
{
	Rectangle rec(x, y, width, height, "");

	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		if (!rec.ContainsPoint(p[i].GetX(), p[i].GetY()))
		{
			return false;
		}
	}
	
	return true;
}

bool Rectangle::IsWithinRegion(const float x, const float y, const float r)
{
	for (int i = 0; i < NUMBER_OF_POINTS; i++)
	{
		float rx = p[i].GetX();
		float ry = p[i].GetY();

		float distance = sqrt((rx - x) * (rx - x) + (ry - y) * (ry - y));
		if (distance > r)
		{
			return false;
		}
	}

	return true;
}

bool Rectangle::ContainsPoint(const float x, const float y)
{
	float x1 = p[0].GetX();
	float x2 = p[3].GetX();

	float y1 = p[0].GetY();
	float y2 = p[0].GetY();

	if (!((x >= x1 && x <= x2) || (x >= x2 && x <= x1)))
	{
		return false;
	}
	if (!((y >= y1 && y <= y2) || (y >= y2 && y <= y1)))
	{
		return false;
	}

	return true;
}

float Rectangle::GetArea()
{
	return width * height;
}

float Rectangle::GetPerimeter()
{
	return 2 * width + 2 * height;
}

SVGElement* Rectangle::clone() const
{
	return new Rectangle(*this);
}

std::fstream& Rectangle::operator<<(std::fstream& st)
{
	st << "<line " << "x=\"" << p[0].GetX() << "\"" << " y=\"" << p[0].GetY() << "\""
		<< " width=\"" << width << "\"" << " height=\"" << height << "\""
		<< " fill=\"" << fill << "\" />\n";

	return st;
}

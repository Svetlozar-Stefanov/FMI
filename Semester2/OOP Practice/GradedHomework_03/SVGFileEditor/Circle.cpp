#include "Circle.h"

Circle::Circle(const float x, const float y, const float r, const svgString& fill)
	: origin(x, y), SVGElement(fill)
{
	this->r = r;
}

svgString Circle::GetInfo()
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
	float newX = origin.GetX() + horiz;
	float newY = origin.GetY() + vert;

	origin.SetX(newX);
	origin.SetY(newY);
}

bool Circle::IsWithinRegion(const float rx, const float ry, const float width, const float height)
{
	float x1 = rx;
	float x2 = rx + width;

	float y1 = ry;
	float y2 = ry + height;

	float x = origin.GetX();
	float y = origin.GetY();

	if (!((x >= x1 && x <= x2)))
	{
		return false;
	}
	if (!((y >= y1 && y <= y2)))
	{
		return false;
	}

	float dis1 = abst(y1 - y);
	if (dis1 < r)
	{
		return false;
	}
	float dis2 = abst(y2 - y);
	if (dis2 < r)
	{
		return false;
	}
	float dis3 = abst(x1 - x);
	if (dis3 < r)
	{
		return false;
	}
	float dis4 = abst(x2 - x);
	if (dis4 < r)
	{
		return false;
	}

	return true;
}

bool Circle::IsWithinRegion(const float x, const float y, const float r)
{
	Circle cir(x, y, r, "");
	if (!cir.ContainsPoint(origin.GetX(), origin.GetY()))
	{
		return false;
	}

	float distance = sqrt((origin.GetX() - x) * (origin.GetX() - x) + (origin.GetY() - y) * (origin.GetY() - y));
	if (distance + this->r > r)
	{
		return false;
	}

	return true;
}

bool Circle::ContainsPoint(const float x, const float y)
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

SVGElement* Circle::clone() const
{
	return new Circle(*this);
}

std::fstream& Circle::operator<<(std::fstream& st)
{
	st << "<circle " << "cx=\"" << origin.GetX() << "\"" << " cy=\"" << origin.GetY() << "\""
		<< " r=\"" << r << "\""
		<< " fill=\"" << fill << "\" />\n";

	return st;
}

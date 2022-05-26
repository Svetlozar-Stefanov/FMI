#pragma once
#include "SVGElement.h"
#include "Point.h"

class Circle :
    public SVGElement
{
private:
    Point origin;
	int r;
public:
    Circle(const int x, const int y, const int r, const svgString& fill);

	svgString getInfo();

	void Translate(const float horiz, const float vert);

	bool isWithinRegion();

	bool ContainsPoint(const int x, const int y);

	float GetArea();

	float GetPerimeter();
};


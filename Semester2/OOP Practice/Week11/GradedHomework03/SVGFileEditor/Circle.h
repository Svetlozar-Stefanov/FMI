#pragma once
#include "SVGElement.h"
#include "Point.h"

class Circle :
    public SVGElement
{
private:
    Point origin;
	float r;
public:
    Circle(const float x, const float y, const float r, const svgString& fill);

	svgString GetInfo();

	void Translate(const float horiz, const float vert);

	bool IsWithinRegion(const float x, const float y, const float width, const float height);

	bool IsWithinRegion(const float x, const float y, const float r);

	bool ContainsPoint(const float x, const float y);

	float GetArea();

	float GetPerimeter();

	SVGElement* clone() const;
};


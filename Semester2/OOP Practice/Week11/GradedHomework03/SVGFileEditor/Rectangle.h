#pragma once
#include "SVGElement.h"
#include "Point.h"

const int NUMBER_OF_POINTS = 4;

class Rectangle :
    public SVGElement
{
private:
    Point p[NUMBER_OF_POINTS];
	float width;
	float height;

public:
    Rectangle(const float x, const float y, const float width, const float height, const svgString &fill);

    svgString GetInfo();

	void Translate(const float horiz, const float vert);

	bool IsWithinRegion(const float x, const float y, const float width, const float height);

	bool IsWithinRegion(const float x, const float y, const float r);

	bool ContainsPoint(const float x, const float y);

	float GetArea();

	float GetPerimeter();

	SVGElement* clone() const;
};


#pragma once
#include "SVGElement.h"
#include "Point.h"

class Rectangle :
    public SVGElement
{
private:
    Point origin;
    int width;
    int height;

public:
    Rectangle(const int x, const int y, const int width, const int height, const svgString &fill);

    svgString GetInfo();

	void Translate(const float horiz, const float vert);

	bool IsWithinRegion(const int x, const int y, const int width, const int height);

	bool IsWithinRegion(const int x, const int y, const int r);

	bool ContainsPoint(const int x, const int y);

	float GetArea();

	float GetPerimeter();

};


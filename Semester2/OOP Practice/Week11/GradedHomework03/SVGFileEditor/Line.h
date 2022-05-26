#pragma once
#include "SVGElement.h"
#include "Point.h"

class Line :
	public SVGElement
{
private:
	Point a;
	Point b;

public:
	Line(const int x1, const int y1,
		const int x2, const int y2, const svgString& fill);

	svgString GetInfo();

	void Translate(const float horiz, const float vert);

	bool IsWithinRegion(const int x, const int y, const int width, const int height);

	bool IsWithinRegion(const int x, const int y, const int r);

	bool ContainsPoint(const int x, const int y);

	float GetArea();

	float GetPerimeter();
};


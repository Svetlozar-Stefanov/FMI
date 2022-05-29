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
	Line(const float x1, const float y1,
		const float x2, const float y2, const svgString& fill);

	svgString GetInfo();

	void Translate(const float horiz, const float vert);

	bool IsWithinRegion(const float x, const float y, const float width, const float height);

	bool IsWithinRegion(const float x, const float y, const float r);

	bool ContainsPoint(const float x, const float y);

	float GetArea();

	float GetPerimeter();

	SVGElement* clone() const;

	std::fstream& operator<<(std::fstream& st);
};


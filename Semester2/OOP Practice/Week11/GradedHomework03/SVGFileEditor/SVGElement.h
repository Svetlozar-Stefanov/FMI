#pragma once
#include "svgString.h"
#include <cmath>

class SVGElement
{
protected:
	svgString fill;

public:
	SVGElement(const svgString &fill);

	virtual svgString GetInfo() = 0;

	virtual void Translate(const float horiz, const float vert) = 0;

	virtual bool IsWithinRegion(const int x, const int y, const int width, const int height) = 0;

	virtual bool IsWithinRegion(const int x, const int y, const int r) = 0;

	virtual bool ContainsPoint(const int x, const int y) = 0;

	virtual float GetArea() = 0;

	virtual float GetPerimeter() = 0;
};
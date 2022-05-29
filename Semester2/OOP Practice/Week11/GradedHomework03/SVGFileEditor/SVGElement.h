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

	virtual bool IsWithinRegion(const float x, const float y, const float width, const float height) = 0;

	virtual bool IsWithinRegion(const float x, const float y, const float r) = 0;

	virtual bool ContainsPoint(const float x, const float y) = 0;

	virtual float GetArea() = 0;

	virtual float GetPerimeter() = 0;

	virtual SVGElement* clone() const = 0;
};
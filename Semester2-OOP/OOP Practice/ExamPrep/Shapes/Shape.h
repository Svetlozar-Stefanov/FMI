#pragma once
#include "Point.h"
#include <cstring>
#include <cmath>
#include <iostream>
#pragma warning(disable:4996)

class Shape
{
public:
	Shape(const Point& origin, const char* color);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();
	

	virtual double GetArea() const = 0;
	virtual double GetParameter() const = 0;

	virtual void Print() const = 0;

	virtual Shape* clone() const = 0;
protected:
	Point origin;
	char* color;

private:

	void copy(const Shape& other);
	void free();
};


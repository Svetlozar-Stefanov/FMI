#pragma once
#include <iostream>
#include "Point.h"

class Control
{
public:
	Control();
	Control(double size, Point& origin);

	const double getSize() const;
	const Point& getOrigin() const;

	void ChangeComponent();

	virtual Control* clone() const = 0;

protected:
	virtual bool SetDataDialog(char* component);
	double size;
	Point origin;
};


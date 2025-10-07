#pragma once
#include "Figure.h"

class Rectangle : public Figure
{
private:
	double mWidth;
	double mHeight;

public:
	Rectangle(double width, double height);

	virtual double getPerimeter() const override;

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;

	virtual unique_ptr<Figure> clone() const override;

	virtual string toString() const override;
};


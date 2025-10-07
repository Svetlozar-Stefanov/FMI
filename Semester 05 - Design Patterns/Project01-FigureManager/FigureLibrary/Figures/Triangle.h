#pragma once
#include "Figure.h"

class Triangle : public Figure
{
private:
	double mA;
	double mB;
	double mC;

public:
	Triangle(double a, double b, double c);

	virtual double getPerimeter() const override;

	bool operator==(const Triangle& other) const;
	bool operator!=(const Triangle& other) const;

	virtual unique_ptr<Figure> clone() const override;

	virtual string toString() const override;
};


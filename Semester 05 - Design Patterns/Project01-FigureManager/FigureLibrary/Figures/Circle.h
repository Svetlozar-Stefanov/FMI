#pragma once
#include "Figure.h"

class Circle : public Figure
{
private:
	double mRadius;
public:
	Circle(double radius);

	virtual double getPerimeter() const override;

	bool operator==(const Circle& other) const;
	bool operator!=(const Circle& other) const;

	virtual unique_ptr<Figure> clone() const override;

	virtual string toString() const override;
};


#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
public:
    Circle(double diameter, const Point& origin, const char* color);

    double GetArea() const override;
    double GetParameter() const override;

    void Print() const override;

    Shape* clone() const override;
protected:
    double diameter;
};


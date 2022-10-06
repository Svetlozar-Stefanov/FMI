#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
public:
    Rectangle(double lenA, double lenB,
        const Point& origin, const char* color);

    double GetArea() const override;
    double GetParameter() const override;

    void Print() const override;

    Shape* clone() const override;
protected:
    double lenA;
    double lenB;
};


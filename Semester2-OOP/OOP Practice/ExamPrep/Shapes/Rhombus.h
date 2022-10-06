#pragma once
#include "Shape.h"
class Rhombus :
    public Shape
{
public:
    Rhombus(double len, double deg,
        const Point& origin, const char* color);

    double GetArea() const override;
    double GetParameter() const override;

    void Print() const override;

    Shape* clone() const override;
protected:
    double len;
    double deg;
};


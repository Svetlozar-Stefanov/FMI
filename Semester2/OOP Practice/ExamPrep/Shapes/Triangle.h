#pragma once
#include "Shape.h"
class Triangle :
    public Shape
{
public:
    Triangle(double lenA, double lenB, double lenC,
        double degAB, double degAC, double degBC,
        const Point& origin, const char* color);

    double GetArea() const override ;
    double GetParameter() const override;

    void Print() const override;

    Shape* clone() const override;
protected:
    double lenA;
    double lenB;
    double lenC;

    double degAB;
    double degAC;
    double degBC;
};


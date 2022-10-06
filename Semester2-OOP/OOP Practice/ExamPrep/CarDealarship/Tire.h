#pragma once
#include "CarPart.h"
class Tire :
    public CarPart
{
public:
    Tire(double width, int profile, double diameter,
        const unsigned id, const char* manufacturer, const char* description);

    const double GetWidth() const;
    const int GetProfile() const;
    const double GetDiameter() const;

    std::ostream& operator<<(std::ostream& os) override;
private:
    double width;
    int profile;
    double diameter;
};


#pragma once
#include "CarPart.h"
class Engine :
    public CarPart
{
public:
    Engine(int hp, const unsigned id, const char* manufacturer, const char* description);

    const int GetHP() const;
    std::ostream& operator<<(std::ostream& os) override;
private:
    int hp;
};


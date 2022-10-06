#pragma once
#include "CarPart.h"
#pragma warning(disable:4996)

class Battery :
    public CarPart
{
public:
    Battery(int capacity, const char* model, const unsigned id, const char* manufacturer, const char* description);
    Battery(const Battery& other);
    Battery& operator=(const Battery& other);
    ~Battery();

    const int GetCapacity() const;
    const char const* GetModel() const;

    std::ostream& operator<<(std::ostream& os) override;
private:
    int capacity;
    char* model;

    void copy(const Battery& other);
    void free();
};


#pragma once
#include "Functions.h"

class ISeafoodDish
{
private:
    void copy(const ISeafoodDish& other);
    void free();

protected:
    char* seafood;

public:
    ISeafoodDish();
    ISeafoodDish(char * seafood);
    ISeafoodDish(const ISeafoodDish& other);
    ISeafoodDish& operator=(const ISeafoodDish& other);
    ~ISeafoodDish();
};


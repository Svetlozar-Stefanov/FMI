#pragma once
#include "ISeafoodDish.h"
#include "Dish.h"

class SeafoodDish : 
   public ISeafoodDish, public Dish 
{
public:
    SeafoodDish();
    SeafoodDish(char* seafood, char** ingredients, int count, int cookTime);

    void Print() const override;
    Dish* clone() const override;
};


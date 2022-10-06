#pragma once
#include "Menu.h"
#include "MeatDish.h"
#include "SeafoodDish.h"
#include "SurfAndTurf.h"

int main()
{
    Menu menu;
    menu.Add(SeafoodDish());
    menu.Add(MeatDish());
    menu.Add(SurfAndTurf());

    menu.Print();
}
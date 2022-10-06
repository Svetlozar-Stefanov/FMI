#pragma once
#include "Dish.h"

class Menu
{
private:
	Dish** dishes;
	int capacity, size;

	void copy(const Menu& other);
	void free();
	void resize();

public:
	Menu();
	Menu(const Menu& other);
	Menu& operator=(const Menu& other);
	~Menu();

	void Add(const Dish& dish);
	void Print() const;
};


#include "Menu.h"

void Menu::copy(const Menu& other)
{
	capacity = other.capacity;
	size = other.size;
	dishes = new Dish * [capacity];
	for (int i = 0; i < size; i++)
	{
		dishes[i] = other.dishes[i]->clone();
	}
}

void Menu::free()
{
	for (int i = 0; i < size; i++)
	{
		delete dishes[i];
	}
	delete[] dishes;
}

void Menu::resize()
{
	Dish** temp = new Dish * [capacity *= 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = dishes[i];
	}
	delete[] dishes;
	dishes = temp;
	temp = nullptr;
}

Menu::Menu()
{
	capacity = 10;
	size = 0;
	dishes = new Dish * [capacity];
	for (int i = 0; i < capacity; i++)
	{
		dishes[i] = nullptr;
	}
}

Menu::Menu(const Menu& other)
{
	copy(other);
}

Menu& Menu::operator=(const Menu& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Menu::~Menu()
{
	free();
}

void Menu::Add(const Dish& dish)
{
	if (size >= capacity)
	{
		resize();
	}
	dishes[size++] = dish.clone();
}

void Menu::Print() const
{
	for (int i = 0; i < size; i++)
	{
		dishes[i]->Print();
	}
}

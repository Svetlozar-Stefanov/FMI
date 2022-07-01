#include "ShapeContainer.h"

ShapeContainer::ShapeContainer()
{
	capacity = 5;
	size = 0;
	shapes = new Shape * [capacity];
	for (int i = 0; i < capacity; i++)
	{
		shapes[i] = nullptr;
	}
}

ShapeContainer::ShapeContainer(const ShapeContainer& other)
{
	copy(other);
}

ShapeContainer& ShapeContainer::operator=(const ShapeContainer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

ShapeContainer::~ShapeContainer()
{
	free();
}

void ShapeContainer::Add(const Shape& shape)
{
	if (size >= capacity)
	{
		resize();
	}
	shapes[size++] = shape.clone();
}

void ShapeContainer::PrintInfo() const
{
	for (int i = 0; i < size; i++)
	{
		shapes[i]->Print();
	}
}

void ShapeContainer::PrintAreas() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << shapes[i]->GetArea() << '\n';
	}
}

void ShapeContainer::PrintPerimeters() const
{
	for (int i = 0; i < size; i++)
	{
		std::cout << shapes[i]->GetParameter() << '\n';
	}
}

void ShapeContainer::copy(const ShapeContainer& other)
{
	capacity = other.capacity;
	size = other.size;
	shapes = new Shape * [capacity];
	for (int i = 0; i < size; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
}

void ShapeContainer::free()
{
	for (int i = 0; i < size; i++)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

void ShapeContainer::resize()
{
	Shape** temp = new Shape * [capacity *= 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = shapes[i];
	}
	delete[] shapes;
	shapes = temp;
	temp = nullptr;

}

#pragma once
#include "Shape.h"
class ShapeContainer
{
public:
	ShapeContainer();
	ShapeContainer(const ShapeContainer& other);
	ShapeContainer& operator=(const ShapeContainer& other);
	~ShapeContainer();

	void Add(const Shape& shape);
	void PrintInfo() const;
	void PrintAreas() const;
	void PrintPerimeters() const;

private:
	Shape** shapes;
	int size, capacity;

	void copy(const ShapeContainer& other);
	void free();
	void resize();
};


#include "Student.h"

void Student::copy(const Student& other)
{
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		grades[i] = other.grades[i];
	}
}

void Student::free()
{
	delete[] grades;
}

Student::Student(int* grades, int size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		this->grades[i] = grades[i];
	}
}

Student::Student(const Student& other)
{
	copy(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

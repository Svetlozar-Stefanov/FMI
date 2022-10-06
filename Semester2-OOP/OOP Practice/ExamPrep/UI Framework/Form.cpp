#include "Form.h"

void Form::copy(const Form& other)
{
	name = other.name;
	width = other.width;
	height = other.height;

	size = other.size;
	capacity = other.capacity;

	controls = new Control * [capacity];
	for (int i = 0; i < size; i++)
	{
		controls[i] = other.controls[i]->clone();
	}
}

void Form::free()
{
	for (int i = 0; i < size; i++)
	{
		delete controls[i];
	}
	delete[] controls;
}

void Form::resize()
{
	Control** temp = new Control * [capacity *= 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = controls[i];
	}
	delete[] controls;
	controls = temp;
	temp = nullptr;
}

Form::Form(std::string& name, double width, double height)
{
	this->name = name;
	this->width = width;
	this->height = height;
	capacity = 5;
	size = 0;
	controls = new Control*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		controls[i] = nullptr;
	}
}

Form::Form(const Form& other)
{
	copy(other);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Form::~Form()
{
	free();
}

void Form::setName(const std::string& name)
{
	this->name = name;
}

void Form::setWidth(const double width)
{
	this->width = width;
}

void Form::setHeight(const double height)
{
	this->height = height;
}

void Form::add(const Control& newControl)
{
	if (size >= capacity)
	{
		resize();
	}
	controls[size++] = newControl.clone();
}

void Form::change(const int index)
{
	if (index > size)
	{
		return;
	}

	controls[index]->ChangeComponent();
}

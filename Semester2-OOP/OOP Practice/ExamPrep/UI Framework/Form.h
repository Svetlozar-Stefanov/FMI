#pragma once
#include "Control.h"

class Form
{
private:
	std::string name;
	double width;
	double height;

	Control** controls;
	int size, capacity;

	void copy(const Form& other);
	void free();
	void resize();

public:
	Form(std::string& name, double width, double height);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	void setName(const std::string& name);
	void setWidth(const double width);
	void setHeight(const double height);
	void add(const Control& newControl);
	void change(const int index);
};


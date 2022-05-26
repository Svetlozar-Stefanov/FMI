#pragma once
#include <iostream>
#include "Functions.h"

class svgString
{
private:
	int MAX_STR_SIZE = 20;

	char* str;
	int index;

	void addLetter(const char l);
	void resize();

public:
	svgString();
	svgString(const char * str);
	svgString(const svgString& other);
	svgString& operator=(const svgString& other);

	const unsigned int GetLength() const;

	svgString& operator+(const svgString& other);
	void operator+=(const svgString& other);

	svgString& operator+(const char* other);
	void operator+=(const char* other);

	svgString& operator+(const int other);
	void operator+=(const int other);

	char operator[](const unsigned int i) const;

	friend std::ostream& operator<<(std::ostream& os, const svgString& str);

	~svgString();
};

std::ostream& operator<<(std::ostream& os, const svgString& str);


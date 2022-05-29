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

	void free();
	void copyobj(const svgString& other);
	void resize();

public:
	svgString();
	svgString(const char * str);
	svgString(const svgString& other);
	svgString& operator=(const svgString& other);

	const char* const GetRaw() const;
	const unsigned int GetLength() const;

	svgString& operator+(const svgString& other);
	void operator+=(const svgString& other);

	svgString& operator+(const char* other);
	void operator+=(const char* other);

	svgString& operator+(const int other);
	void operator+=(const int other);

	svgString& operator+(const float other);
	void operator+=(const float other);

	char operator[](const unsigned int i) const;

	bool operator==(const char* str);

	friend std::ostream& operator<<(std::ostream& os, const svgString& str);

	~svgString();
};

std::ostream& operator<<(std::ostream& os, const svgString& str);


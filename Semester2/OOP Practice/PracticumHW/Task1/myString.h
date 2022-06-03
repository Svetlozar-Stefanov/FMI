#pragma once
#include <iostream>
#include "Functions.h"

class myString
{
private:
	char* str;
	int index;
	int size;

	void addLetter(const char l);

	void free();
	void copyobj(const myString& other);
	void resize();

public:
	myString();
	myString(const char * str);
	myString(const myString& other);
	myString& operator=(const myString& other);

	const unsigned int GetLength() const;

	myString& operator+(const myString& other);
	void operator+=(const myString& other);

	myString& operator+(const char* other);
	void operator+=(const char* other);

	myString& operator+(const int other);
	void operator+=(const int other);

	myString& operator+(const float other);
	void operator+=(const float other);

	char operator[](const unsigned int i) const;

	bool operator==(const char* str) const;

	bool operator==(const myString& str) const;

	bool operator!=(const char* str) const;

	bool operator!=(const myString& str) const;

	friend std::ostream& operator<<(std::ostream& os, const myString& str);
	friend std::fstream& operator<<(std::fstream& os, const myString& str);

	~myString();
};

std::ostream& operator<<(std::ostream& os, const myString& str);

std::fstream& operator<<(std::fstream& os, const myString& str);


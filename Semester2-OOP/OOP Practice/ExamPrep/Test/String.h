#pragma once
#include <iostream>

class String
{
private:
	char* str;
	int size;
	
	void copy(const String& other);
	void free();

public:
	String();
	String(const char* s);
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other);
	String& operator=(String&& other);
	~String();

	int get_size() const;

	const char operator[](const int i) const;
	char& operator[](const int i);

	friend String operator+(const String& s1, const String& s2);
	String& operator+=(const String& s);

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& os, String& s);
};


#include "String.h"

void String::copy(const String& other)
{
	size = other.size;
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		str[i] = other.str[i];
	}
	str[size] = '\0';
}

void String::free()
{
	delete[] str;
}

String::String()
{
	size = 0;
	str = new char[size + 1];
	str[size] = '\0';
}

String::String(const char* s)
{
	size = strlen(s);
	str = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		str[i] = s[i];
	}
	str[size] = '\0';
}

String::String(const String& other)
{
	copy(other);
}


String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

String::String(String&& other):str(other.str), size(other.size)
{
	other.str = nullptr;
}

String& String::operator=(String&& other)
{
	if (this != &other)
	{
		free();
		str = other.str;
		other.str = nullptr;
		size = other.size;
	}

	return *this;
}

String::~String()
{
	free();
}

int String::get_size() const
{
	return size;
}

const char String::operator[](const int i) const
{
	if (i >= size)
	{
		throw "out of range";
	}
	return str[i];
}

char& String::operator[](const int i)
{
	if (i >= size)
	{
		throw "out of range";
	}
	return str[i];
}

String& String::operator+=(const String& s)
{
	return *this = *this + s;
}

String operator+(const String& s1, const String& s2)
{
	int size = s1.size + s2.size;
	char* temp = new char[size + 1];
	for (int i = 0; i < s1.size; i++)
	{
		temp[i] = s1.str[i];
	}
	for (int i = 0; i < s2.size; i++)
	{
		temp[i + s1.size] = s2.str[i];
	}
	temp[size] = '\0';
	
	String s(temp);
	delete[] temp;

	return s;
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

std::istream& operator>>(std::istream& os, String& s)
{
	char buffer[100];
	os.getline(buffer, 100);
	s = String(buffer);

	return os;
}

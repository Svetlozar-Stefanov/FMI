#include "myString.h"


void myString::addLetter(const char l)
{
	if (index >= size)
	{
		resize();
	}

	str[index] = l;
	if (l != '\0')
	{
		index++;
	}
}

void myString::free()
{
	delete[] str;
}

void myString::copyobj(const myString& other)
{
	size = other.size;
	str = new char[size];
	for (int i = 0; i <= other.GetLength(); i++)
	{
		str[i] = other.str[i];
	}
	index = other.index;
}

void myString::resize()
{
	size *= 2;
	char* newStr = new char[size];
	for (int i = 0; i <= this->GetLength(); i++)
	{
		newStr[i] = str[i];
	}

	delete[] str;

	str = newStr;
}

myString::myString()
{
	size = 20;
	str = new char[size];
	str[0] = '\0';
	index = 0;
}

myString::myString(const char* str)
{
	size = strleng(str) * 2;
	this->str = new char[size];
	for (int i = 0; i <= strleng(str); i++)
	{
		this->str[i] = str[i];
	}
	index = strleng(str);
}

myString::myString(const myString& other)
{
	copyobj(other);
}

myString& myString::operator=(const myString& other)
{
	if (this != &other)
	{
		free();
		copyobj(other);
	}
	return *this;
}

const unsigned int myString::GetLength() const
{
	if (index == 0)
	{
		return 1;
	}
	return index;
}

myString& myString::operator+(const myString& other)
{
	for (int i = 0; i <= other.GetLength(); i++)
	{
		addLetter(other[i]);
	}

	return *this;
}

void myString::operator+=(const myString& other)
{
	for (int i = 0; i <= other.GetLength(); i++)
	{
		addLetter(other[i]);
	}
}

myString& myString::operator+(const char* other)
{
	for (int i = 0; i <= strleng(other); i++)
	{
		addLetter(other[i]);
	}

	return *this;
}

void myString::operator+=(const char* other)
{
	for (int i = 0; i <= strleng(other); i++)
	{
		addLetter(other[i]);
	}
}

myString& myString::operator+(const int other)
{
	char* temp = itos(other);
	operator+=(temp);

	delete[] temp;

	return *this;
}

void myString::operator+=(const int other)
{
	char* temp = itos(other);
	operator+=(temp);

	delete[] temp;
}

myString& myString::operator+(const float other)
{
	char* temp = ftos(other);
	operator+=(temp);

	delete[] temp;

	return *this;
}

void myString::operator+=(const float other)
{
	char* temp = ftos(other);
	operator+=(temp);

	delete[] temp;
}

char myString::operator[](const unsigned int i) const
{
	if (i >= size)
	{
		return '\0';
	}
	return str[i];
}

bool myString::operator==(const char* str) const
{
	return strcomp(this->str, str);
}

bool myString::operator==(const myString& str) const
{
	return strcomp(this->str, str.str);
}

bool myString::operator!=(const char* str) const
{
	return !strcomp(this->str, str);
}

bool myString::operator!=(const myString& str) const
{
	return !strcomp(this->str, str.str);
}

myString::~myString()
{
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const myString& str)
{
	os << str.str;
	return os;
}

std::fstream& operator<<(std::fstream& os, const myString& str)
{
	return os << str.str;
}

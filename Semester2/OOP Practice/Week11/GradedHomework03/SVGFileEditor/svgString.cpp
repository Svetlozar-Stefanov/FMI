#include "svgString.h"


void svgString::addLetter(const char l)
{
	if (index >= MAX_STR_SIZE)
	{
		resize();
	}

	str[index] = l;
	if (l != '\0')
	{
		index++;
	}
}

void svgString::free()
{
	delete[] str;
}

void svgString::copyobj(const svgString& other)
{
	str = copy(other.str);
	index = other.index;
}

void svgString::resize()
{
	MAX_STR_SIZE *= 2;
	char* newStr = new char[MAX_STR_SIZE];
	for (int i = 0; i <= this->GetLength(); i++)
	{
		newStr[i] = str[i];
	}
	delete[] str;

	str = newStr;
}

svgString::svgString()
{
	str = new char[MAX_STR_SIZE];
	str[0] = '\0';
	index = 0;
}

svgString::svgString(const char* str)
{
	this->str = copy(str);
	index = strleng(str);
}

svgString::svgString(const svgString& other)
{
	copyobj(other);
}

svgString& svgString::operator=(const svgString& other)
{
	if (this != &other)
	{
		free();
		copyobj(other);
	}
	return *this;
}

const unsigned int svgString::GetLength() const
{
	if (index == 0)
	{
		return 1;
	}
	return index;
}

svgString& svgString::operator+(const svgString& other)
{
	for (int i = 0; i <= other.GetLength(); i++)
	{
		addLetter(other[i]);
	}

	return *this;
}

void svgString::operator+=(const svgString& other)
{
	for (int i = 0; i <= other.GetLength(); i++)
	{
		addLetter(other[i]);
	}
}

svgString& svgString::operator+(const char* other)
{
	for (int i = 0; i <= strleng(other); i++)
	{
		addLetter(other[i]);
	}

	return *this;
}

void svgString::operator+=(const char* other)
{
	for (int i = 0; i <= strleng(other); i++)
	{
		addLetter(other[i]);
	}
}

svgString& svgString::operator+(const int other)
{
	char* temp = itos(other);
	operator+=(temp);

	delete[] temp;

	return *this;
}

void svgString::operator+=(const int other)
{
	char* temp = itos(other);
	operator+=(temp);

	delete[] temp;
}

svgString& svgString::operator+(const float other)
{
	char* temp = ftos(other);
	operator+=(temp);

	delete[] temp;

	return *this;
}

void svgString::operator+=(const float other)
{
	char* temp = ftos(other);
	operator+=(temp);

	delete[] temp;
}

char svgString::operator[](const unsigned int i) const
{
	if (i >= MAX_STR_SIZE)
	{
		return '\0';
	}
	return str[i];
}

svgString::~svgString()
{
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const svgString& str)
{
	os << str.str;
	return os;
}

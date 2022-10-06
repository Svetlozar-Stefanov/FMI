#include "Complex.h"

Complex::Complex()
{
	r = 0;
	i = 0;
}

Complex::Complex(double r, double i)
{
	this->r = r;
	this->i = i;
}

double Complex::getR() const
{
	return r;
}

double Complex::getI() const
{
	return i;
}

Complex& Complex::operator+=(const Complex& other)
{
	*this = *this + other;

	return *this;
}

Complex& Complex::operator*=(const Complex& other)
{
	*this = *this + other;
	return *this;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1.r + c2.r, c1.i + c2.i);
}

Complex operator*(const Complex& c1, const Complex& c2)
{
	return Complex(c1.r*c2.r - c1.i * c1.i, c1.r * c2.i + c1.i * c2.r);
}

bool operator==(const Complex& c1, const Complex& c2)
{
	return ((c1.r == c2.r) && (c1.i == c2.i));
}

bool operator!=(const Complex& c1, const Complex& c2)
{
	return !(c1 == c2);
}

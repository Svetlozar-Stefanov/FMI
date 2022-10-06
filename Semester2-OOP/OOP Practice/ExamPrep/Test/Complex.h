#pragma once
class Complex
{
private:
	double r;
	double i;

public:
	Complex();
	Complex(double r, double i);

	double getR() const;
	double getI() const;

	friend Complex operator+(const Complex& c1, const Complex& c2);
	Complex& operator+=(const Complex& other);

	friend Complex operator*(const Complex& c1, const Complex& c2);
	Complex& operator*=(const Complex& other);

	friend bool operator==(const Complex& c1, const Complex& c2);
	friend bool operator!=(const Complex& c1, const Complex& c2);
};


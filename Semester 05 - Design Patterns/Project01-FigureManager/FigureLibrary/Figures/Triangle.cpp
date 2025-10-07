#include <stdexcept>
#include <sstream>

#include "Triangle.h"
#include "../Utils/MathUtils.h"

using std::invalid_argument;
using std::stringstream;
using std::make_unique;

Triangle::Triangle(double a, double b, double c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		throw invalid_argument("Side cannot be non-positive number.");
	}
	if (a >= c + b || b >= a + c || c >= a + b)
	{
		throw invalid_argument("Violates law of triangle inequality.");
	}

	mA = a;
	mB = b;
	mC = c;
}

double Triangle::getPerimeter() const
{
	return mA + mB + mC;
}

bool Triangle::operator==(const Triangle& other) const
{
	return epseq(mA, other.mA)
		&& epseq(mB, other.mB)
		&& epseq(mC, other.mC);
}

bool Triangle::operator!=(const Triangle& other) const
{
	return !(*this == other);
}

unique_ptr<Figure> Triangle::clone() const
{
	return make_unique<Triangle>(*this);
}

string Triangle::toString() const
{
	stringstream sstrm;
	sstrm << "triangle " << mA << " " << mB << " " << mC;
	return sstrm.str();
}
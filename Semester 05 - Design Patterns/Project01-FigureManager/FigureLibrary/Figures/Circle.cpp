#include <stdexcept>
#include <math.h>
#include <sstream>
#include <memory>

#include "Circle.h"
#include "../Utils/MathUtils.h"

using std::invalid_argument;
using std::stringstream;
using std::make_unique;


Circle::Circle(double radius)
{
	if (radius <= 0)
	{
		throw invalid_argument("Radius of circle cannot be non-positive.");
	}

	mRadius = radius;
}

double Circle::getPerimeter() const
{
	return 2 * PI * mRadius;
}

bool Circle::operator==(const Circle& other) const
{
	return epseq(mRadius, other.mRadius);
}

bool Circle::operator!=(const Circle& other) const
{
	return !(*this == other);
}

unique_ptr<Figure> Circle::clone() const
{
	return make_unique<Circle>(*this);
}

string Circle::toString() const
{
	stringstream sstrm;
	sstrm << "circle " << mRadius;
	return sstrm.str();
}

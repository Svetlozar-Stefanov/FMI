#include <stdexcept>
#include <sstream>
#include <memory>

#include "Rectangle.h"
#include "../Utils/MathUtils.h"

using std::invalid_argument;
using std::stringstream;
using std::make_unique;

Rectangle::Rectangle(double width, double height)
{
	if (width <= 0 || height <= 0)
	{
		throw invalid_argument("Sides of rectangle cannot be non-positive.");
	}

	mWidth = width;
	mHeight = height;
}

double Rectangle::getPerimeter() const
{
	return 2 * mWidth + 2 * mHeight;
}

bool Rectangle::operator==(const Rectangle& other) const
{
	return epseq(mWidth, other.mWidth)
		&& epseq(mHeight, other.mHeight);
}

bool Rectangle::operator!=(const Rectangle& other) const
{
	return !(*this == other);
}

unique_ptr<Figure> Rectangle::clone() const
{
	return make_unique<Rectangle>(*this);
}

string Rectangle::toString() const
{
	stringstream sstrm;
	sstrm << "rectangle " << mWidth << " " << mHeight;
	return sstrm.str();
}

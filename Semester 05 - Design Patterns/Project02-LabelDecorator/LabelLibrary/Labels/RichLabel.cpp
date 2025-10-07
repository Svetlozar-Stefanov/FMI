#include "RichLabel.h"

using std::string;

RichLable::RichLable(const string& value, const RGBColor& color, int size, const string& font)
	: mValue(value), mColor(color), mSize(size), mFont(font)
{}

std::string RichLable::getText() const
{
	return mValue;
}
#include "SimpleLabel.h"

using std::string;

SimpleLabel::SimpleLabel(const string& value)
	: mValue(value)
{}

string SimpleLabel::getText() const
{
	return mValue;
}
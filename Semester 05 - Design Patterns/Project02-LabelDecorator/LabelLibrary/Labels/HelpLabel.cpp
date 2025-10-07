#include "HelpLabel.h"

using std::string;

HelpLabel::HelpLabel(Label* label, string helperText)
	: mLabel(label), mHelperText(helperText)
{}

HelpLabel::~HelpLabel()
{
	if (mLabel != nullptr)
	{
		delete mLabel;
	}
}

string HelpLabel::getText() const
{
	return mLabel->getText();
}

std::string HelpLabel::getHelperText() const
{
	return mHelperText;
}
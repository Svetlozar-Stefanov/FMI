#pragma once
#include "TextTransformation.h"

#include <string>

class LeftTrimTransformation : public TextTransformation
{
public:
	LeftTrimTransformation();
	std::string transform(std::string text) const override;
};


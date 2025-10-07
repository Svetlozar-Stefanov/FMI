#pragma once
#include "TextTransformation.h"

#include <string>

class RightTrimTransformation : public TextTransformation
{
public:
	RightTrimTransformation();
	std::string transform(std::string text) const override;
};
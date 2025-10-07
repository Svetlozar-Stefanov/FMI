#pragma once
#include "Label.h"

#include <string>

struct RGBColor {
	float r, g, b;
};

class RichLable : public Label {
private:
	std::string mValue;

	RGBColor mColor;
	
	int mSize;

	std::string mFont;

public:
	RichLable(const std::string& value, const RGBColor& color, int size, const std::string& font);
	
	std::string getText() const override;
};
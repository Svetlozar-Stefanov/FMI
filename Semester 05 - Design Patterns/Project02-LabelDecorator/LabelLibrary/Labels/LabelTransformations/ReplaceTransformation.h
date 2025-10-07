#pragma once
#include "TextTransformation.h"

#include <string>

class ReplaceTransformation : public TextTransformation {
private:
	std::string mToReplace;
	std::string mReplacement;
public:
	ReplaceTransformation(const std::string& toReplace, const std::string& replacement);

	std::string transform(std::string text) const;
};
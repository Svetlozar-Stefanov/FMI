#pragma once
#include <string>

enum class TransformationType {
	UNKNOWN,
	COMPOSITE,
	CAPITALIZE,
	CENSOR,
	DECORATE,
	LEFT_TRIM,
	RIGHT_TRIM,
	REPLACE,
	NORMALIZE_SPACE
};

class TextTransformation {
protected:
	TransformationType mType;
public:
	virtual ~TextTransformation() {};

	virtual std::string transform(std::string text) const = 0;
	TransformationType getType() const;
	virtual bool isOfType(TransformationType type) const;
};
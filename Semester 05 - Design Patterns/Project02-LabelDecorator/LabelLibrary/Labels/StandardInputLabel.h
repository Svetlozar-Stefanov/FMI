#pragma once
#include "Label.h"

#include <string>

class StandardInputLabel : public Label {
private:
	mutable std::string mText;
	mutable int mRequests;
	mutable bool mFirst;
	int mTimeout;

public:
	StandardInputLabel(int timeout);
	std::string getText() const override;
};
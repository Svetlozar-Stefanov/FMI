#pragma once
#include "Label.h"

class HelpLabel : public Label {
private:
	Label* mLabel;
	std::string mHelperText;
public:
	HelpLabel(Label* label, std::string helperText);
	~HelpLabel() override;

	std::string getText() const override;
	std::string getHelperText() const;
};
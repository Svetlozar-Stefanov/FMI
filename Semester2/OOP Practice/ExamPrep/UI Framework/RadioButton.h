#pragma once
#include "Control.h"
class RadioButton :
    public Control
{
public:
    RadioButton();
    RadioButton(int current, std::string* options, int count, double size, Point& origin);
    RadioButton(const RadioButton& other);
    RadioButton& operator=(const RadioButton& other);
    ~RadioButton();

    const std::string& getOption() const;

    Control* clone() const override;

protected:
    std::string* options;
    int count;
    int current;


    bool SetDataDialog(char* component) override;

private:
    void copy(const RadioButton& other);
    void free();
};


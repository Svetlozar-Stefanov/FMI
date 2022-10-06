#include "RadioButton.h"

RadioButton::RadioButton()
{
    size = 1;
    current = 0;
    options = new std::string[size];
    options[0] = std::string();
}

RadioButton::RadioButton(int current, std::string* options, int count, double size, Point& origin)
    : Control(size, origin)
{
    this->current = current;
    this->count = count;
    for (int i = 0; i < this->count; i++)
    {
        this->options[i] = options[i];
    }
}

RadioButton::RadioButton(const RadioButton& other)
{
    copy(other);
}

RadioButton& RadioButton::operator=(const RadioButton& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

RadioButton::~RadioButton()
{
    free();
}

const std::string& RadioButton::getOption() const
{
    return options[current];
}

Control* RadioButton::clone() const
{
    return new RadioButton(*this);
}

bool RadioButton::SetDataDialog(char* component)
{
    char buffer[100];
    if (Control::SetDataDialog(component))
    {
        return true;
    }
    if (strcmp(component, "pick option"))
    {
        std::cin.getline(buffer, 100);
        current = atoi(buffer);
        return true;
    }
    if (strcmp(component, "change option"))
    {
        std::cin.getline(buffer, 100);
        int index = atoi(buffer);

        std::cin.getline(buffer, 100);
        std::string newStr = buffer;

        options[index] = newStr;

        return true;
    }

    return false;
}

void RadioButton::copy(const RadioButton& other)
{
    count = other.count;
    for (int i = 0; i < count; i++)
    {
        options[i] = other.options[i];
    }
    current = other.current;
}

void RadioButton::free()
{
    delete[] options;
}

#pragma once
#include <stdexcept>
#include <string>

class insufficient_fuel_error : public std::logic_error
{
public:
	insufficient_fuel_error(std::string error_message);
};


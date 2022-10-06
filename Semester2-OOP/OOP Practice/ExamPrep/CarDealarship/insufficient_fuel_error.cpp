#include "insufficient_fuel_error.h"

insufficient_fuel_error::insufficient_fuel_error(std::string error_message)
	: logic_error(error_message)
{
}

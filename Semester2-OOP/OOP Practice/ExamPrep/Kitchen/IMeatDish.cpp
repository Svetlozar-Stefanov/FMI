#include "IMeatDish.h"

IMeatDish::IMeatDish()
{
	meat = MeatType::UNKNOWN;
}

IMeatDish::IMeatDish(MeatType meat)
{
	this->meat = meat;
}

#pragma once

class IMeatDish
{
protected:
	enum MeatType
	{
		CHICKEN,
		BEEF,
		PORK,
		DUCK,
		UNKNOWN
	} meat;

public:
	IMeatDish();
	IMeatDish(MeatType meat);
};


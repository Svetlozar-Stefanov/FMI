#pragma once
#pragma warning(disable:4996)
#include <cstring>
#include <fstream>

class CarPart
{
public:
	CarPart(const unsigned id, const char* manufacturer, const char* description);
	CarPart(const CarPart& other);
	CarPart& operator=(const CarPart& other);
	~CarPart();

	const unsigned GetID() const;
	const char const* GetManufacturer() const;
	const char const* GetDescription() const;

	virtual std::ostream& operator<<(std::ostream& os);

protected:
	unsigned id;
	char* manufacturer;
	char* description;

	void copy(const CarPart& other);
	void free();
};


#pragma once
#include <vector>
#include "GuitarItem.h"

class Inventory
{
private:
	std::vector<GuitarItem> inventory;

public:
	void addGuitar(const GuitarItem& guitar);
	GuitarItem* getGuitar(const std::string serialNumber);

	std::vector<GuitarItem> search(const Guitar& searchedGuitar);
};


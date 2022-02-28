#include "Inventory.h"

void Inventory::addGuitar(const GuitarItem& guitar)
{
	inventory.push_back(guitar);
}

GuitarItem* Inventory::getGuitar(const std::string serialNumber)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].SerialNumber == serialNumber)
		{
			return &inventory[i];
		}
	}
}

std::vector<GuitarItem> Inventory::search(const Guitar& searchedGuitar)
{
	std::vector<GuitarItem> foundGuitars;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].Item.GuitarBuilder == searchedGuitar.GuitarBuilder
			&& inventory[i].Item.Model == searchedGuitar.Model
			&& inventory[i].Item.GuitarType == searchedGuitar.GuitarType
			&& inventory[i].Item.BackWood == searchedGuitar.BackWood
			&& inventory[i].Item.TopWood == searchedGuitar.TopWood)
		{
			foundGuitars.push_back(inventory[i]);
		}
	}

	return foundGuitars;
}

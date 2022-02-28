#pragma once
#include "Guitar.h"
#include "ShopItem.h"

class GuitarItem : public ShopItem
{
public:

	Guitar Item;

	GuitarItem(const std::string serialNumber, const double price, const Guitar guitar);
};


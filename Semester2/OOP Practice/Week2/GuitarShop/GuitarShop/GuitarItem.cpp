#include "GuitarItem.h"

GuitarItem::GuitarItem(const std::string serialNumber, const double price, const Guitar guitar)
	:ShopItem(serialNumber, price)
{
	Item = guitar;
}

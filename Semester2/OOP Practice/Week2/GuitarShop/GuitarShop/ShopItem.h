#pragma once
#include<string>

class ShopItem
{
public:
	std::string SerialNumber;
	double Price;

	ShopItem(const std::string serialNumber, const double price);
};


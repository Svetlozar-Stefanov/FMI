#include <iostream>
#include"Inventory.h"

int main()
{
    Inventory inv;

    GuitarItem g1 = GuitarItem("1234", 123.0, Guitar(Builder::Fender, "4", Type::Stratocaster, Wood::Oak, Wood::Oak));
    GuitarItem g2 = GuitarItem("1234", 123.0, Guitar(Builder::Fender, "4", Type::Stratocaster, Wood::Birch, Wood::Birch));

    inv.addGuitar(g1);
    inv.addGuitar(g2);

    std::vector<GuitarItem> guitarsFound = inv.search(Guitar(Builder::Fender, "4", Type::Stratocaster, Wood::Oak, Wood::Oak));
}
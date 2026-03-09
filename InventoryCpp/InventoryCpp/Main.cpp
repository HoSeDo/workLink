#include <iostream>
#include "Inventory.h"
#include "Item.h"

bool compareItemsByPrice(const Item& a, const Item& b)
{
    return a.GetPrice() < b.GetPrice();
}

int main()
{
    Inventory<Item> inv(2);

    inv.AddItem(Item("Sword", 100));
    inv.AddItem(Item("Potion", 50));
    inv.AddItem(Item("Bow", 120));
    inv.AddItem(Item("Shield", 80));

    std::cout << "정렬 전\n";
    inv.PrintAllItems();

    inv.SortItems(compareItemsByPrice);

    std::cout << "\n정렬 후\n";
    inv.PrintAllItems();
}


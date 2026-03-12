#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

class Inventory
{
private:
    std::unordered_map<std::string, int> items;

public:
    void addItem(const std::string& name, int amount);
    void removeItem(const std::string& name, int amount);
    void showInventory() const;
};

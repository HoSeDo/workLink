#pragma once
#include <string>
#include <unordered_map>

enum class ItemType
{
    Ingredient,
    Currency
};

struct Ingredient
{
    std::string name;
    int maxStack;
    ItemType type;

    Ingredient(const std::string& name = "",
        int maxStack = 99,
        ItemType type = ItemType::Ingredient);
};

class IngredientDatabase
{
private:
    std::unordered_map<std::string, Ingredient> ingredients;

public:
    void addIngredient(const std::string& name, ItemType type);
    bool exists(const std::string& name) const;
    ItemType getType(const std::string& name) const;
};
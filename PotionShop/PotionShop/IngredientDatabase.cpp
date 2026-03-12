#include "IngredientDatabase.h"

Ingredient::Ingredient(const std::string& name, int maxStack, ItemType type)
    : name(name), maxStack(maxStack), type(type)
{
}

void IngredientDatabase::addIngredient(const std::string& name, ItemType type)
{
    ingredients.emplace(name, Ingredient(name, 99, type));
}

bool IngredientDatabase::exists(const std::string& name) const
{
    return ingredients.find(name) != ingredients.end();
}

ItemType IngredientDatabase::getType(const std::string& name) const
{
    return ingredients.at(name).type;
}
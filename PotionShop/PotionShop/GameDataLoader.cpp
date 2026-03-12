#include "GameDataLoader.h"

void initializeGameData(
    IngredientDatabase& db,
    Inventory& inventory,
    AlchemyWorkshop& workshop)
{
    db.addIngredient("블러디허브", ItemType::Ingredient);
    db.addIngredient("정제수", ItemType::Ingredient);
    db.addIngredient("마나허브", ItemType::Ingredient);
    db.addIngredient("빈병", ItemType::Ingredient);

    db.addIngredient("동화", ItemType::Currency);
    db.addIngredient("은화", ItemType::Currency);
    db.addIngredient("금화", ItemType::Currency);

    inventory.addItem("블러디허브", 5);
    inventory.addItem("정제수", 5);
    inventory.addItem("마나허브", 5);
    inventory.addItem("빈병", 5);

    workshop.addRecipe("체력 포션", { "빈병", "블러디허브", "정제수" });
    workshop.addRecipe("마나 포션", { "빈병", "마나허브", "정제수" });
}
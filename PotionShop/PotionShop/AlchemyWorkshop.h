#pragma once
#ifndef ALCHEMYWORKSHOP_H
#define ALCHEMYWORKSHOP_H

#include <vector>
#include <string>
#include "PotionRecipe.h"
#include <unordered_map>

class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;
    std::unordered_map<std::string, int> inventory;

public:
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    void displayAllRecipes() const;

    //검색 함수
    void searchByPotionName(const std::string& name) const;
    void searchByIngredient(const std::string& ingredient) const;

    //포션 찾기 와 포션 주기
    void findPotion(const std::string& keyword) const;
    void givePotion(const std::string& name);

    //공병 돌려받기
    void returnPotion(const std::string& name);
};

#endif
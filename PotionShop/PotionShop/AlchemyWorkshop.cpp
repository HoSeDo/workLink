#include "AlchemyWorkshop.h"
#include <iostream>

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) 
{
    recipes.emplace_back(name, ingredients);
    // 초기 재고 3개 지급
    inventory[name] = 3;

    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

//레시피 출력 (물약이름, 재고, 필요재료)
void AlchemyWorkshop::displayAllRecipes() const {
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;

    for (const auto& recipe : recipes) {
        std::cout << "- 물약 이름: " << recipe.potionName << std::endl; 
        std::cout << "  재고: " << inventory.at(recipe.potionName) << std::endl;

        std::cout << "  > 필요 재료: ";

        for (size_t i = 0; i < recipe.ingredients.size(); ++i) {
            std::cout << recipe.ingredients[i];

            if (i < recipe.ingredients.size() - 1)
                std::cout << ", ";
        }

        std::cout << std::endl;
    }

    std::cout << "---------------------------\n";
}

//포션 이름 검색
void AlchemyWorkshop::searchByPotionName(const std::string& name) const {

    for (const auto& recipe : recipes) {

        if (recipe.potionName == name) {

            std::cout << "\n[검색 결과]" << std::endl;
            std::cout << "물약 이름: " << recipe.potionName << std::endl;
            std::cout << "필요 재료: ";

            for (size_t i = 0; i < recipe.ingredients.size(); i++) {
                std::cout << recipe.ingredients[i];

                if (i < recipe.ingredients.size() - 1)
                    std::cout << ", ";
            }

            std::cout << std::endl;
            return;
        }
    }

    std::cout << "해당 이름의 레시피가 없습니다." << std::endl;
}

//포션 사용 재료 검색
void AlchemyWorkshop::searchByIngredient(const std::string& ingredient) const {

    bool found = false;

    std::cout << "\n[재료 검색 결과]\n";

    for (const auto& recipe : recipes) {

        for (const auto& ing : recipe.ingredients) {

            if (ing == ingredient) {

                std::cout << "물약: " << recipe.potionName << std::endl;

                found = true;
                break;
            }
        }
    }

    if (!found)
        std::cout << "해당 재료가 들어간 레시피가 없습니다." << std::endl;
}
// 종합 포션 검색
void AlchemyWorkshop::findPotion(const std::string& keyword) const {

    bool found = false;

    std::cout << "\n[검색 결과]\n";

    for (const auto& recipe : recipes) {

        // 물약 이름 부분 검색
        if (recipe.potionName.find(keyword) != std::string::npos) {
            std::cout << "물약: " << recipe.potionName << std::endl;
            found = true;
            continue;
        }

        // 재료 부분 검색
        for (const auto& ing : recipe.ingredients) {

            if (ing.find(keyword) != std::string::npos) {
                std::cout << "물약: " << recipe.potionName << std::endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        std::cout << "검색 결과가 없습니다." << std::endl;
    }
}

//포션 지급
void AlchemyWorkshop::givePotion(const std::string& name) {

    if (inventory[name] > 0) {

        inventory[name]--;

        std::cout << "모험가에게 '" << name << "' 물약을 지급했습니다." << std::endl;
        std::cout << "남은 재고: " << inventory[name] << std::endl;
    }
    else {

        std::cout << "재고가 부족합니다." << std::endl;
    }
}

//공병 돌려받기
void AlchemyWorkshop::returnPotion(const std::string& name)
{
    auto it = inventory.find(name);

    if (it == inventory.end())
    {
        std::cout << "존재하지 않는 물약입니다.\n";
        return;
    }

    if (it->second >= 3)
    {
        std::cout << "창고가 가득 찼습니다. 더 이상 반환할 수 없습니다.\n";
        return;
    }

    it->second++;

    std::cout << "'" << name << "' 물약을 돌려받았습니다.\n";
    std::cout << "현재 재고: " << it->second << std::endl;
}
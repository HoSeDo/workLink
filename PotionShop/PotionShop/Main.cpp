#include <iostream>
#include "AlchemyWorkshop.h"

int main()
{
    AlchemyWorkshop workshop;

    // 초기 레시피
    workshop.addRecipe("체력 포션", { "블러디허브", "정제수" });
    workshop.addRecipe("마나 포션", { "마나허브", "정제수" });

    while (true)
    {
        std::cout << "연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 목록 보기" << std::endl;
        std::cout << "2. 물약 이름 검색" << std::endl;
        std::cout << "3. 재료 이름 검색" << std::endl;
        std::cout << "4. 물약 및 재료 이름 검색" << std::endl;
        std::cout << "5. 물약 지급" << std::endl;
        std::cout << "6. 공병 반환" << std::endl;
        std::cout << "7. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (choice == 1)
        {
            workshop.displayAllRecipes();
        }
       
        else if (choice == 2)
        {
            std::string name;
            std::cout << "검색할 물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            workshop.searchByPotionName(name);
        }
       
        else if (choice == 3)
        {
            std::string ingredient;
            std::cout << "검색할 재료: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ingredient);

            workshop.searchByIngredient(ingredient);
        }

        else if (choice == 4)
        {
            std::string keyword;

            std::cout << "검색어 입력: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, keyword);

            workshop.findPotion(keyword);
        }

        else if (choice == 5)
        {
            std::string name;
            std::cout << "지급할 물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            workshop.givePotion(name);
        }
        
        else if (choice == 6)
        {
            std::string name;
            std::cout << "반환할 물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            workshop.returnPotion(name);
        }
       
        else if (choice == 7)
        {
            std::cout << "공방 문을 닫습니다." << std::endl;
            break;
        }
        else
        {
            std::cout << "잘못된 입력입니다." << std::endl;
        }
    }

    return 0;
}
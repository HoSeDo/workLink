#include "Inventory.h"

//아이템 추가 99개가 초과하면 나머진 자동파기
void Inventory::addItem(const std::string& name, int amount)
{
    int& count = items[name];

    count += amount;

    if (count > 99)
    {
        int destroyed = count - 99;

        std::cout << name << "의 갯수가 초과되어 "
            << destroyed
            << "개가 파기되었습니다." << std::endl;

        count = 99;
    }
}

void Inventory::removeItem(const std::string& name, int amount)
{
    auto it = items.find(name);

    if (it == items.end())
        return;

    it->second -= amount;

    if (it->second < 0)
        it->second = 0;
}

void Inventory::showInventory() const
{
    std::cout << std::endl;
    std::cout << "[재료 인벤토리]" << std::endl;

    for (const auto& item : items)
    {
        std::cout << item.first << " : " << item.second << std::endl;
    }
}
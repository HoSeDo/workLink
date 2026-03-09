#pragma once
#include <string>

class Item
{
public:
    Item();
    Item(const std::string& name, int price);

    const std::string& GetName() const;
    int GetPrice() const;

    void Clear()
    {
        name_ = "";
        price_ = 0;
    }

private:
    std::string name_;
    int price_;
};
#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class Inventory
{
private:
    T* pItems_;
    int capacity_;
    int size_;

public:
    Inventory(int capacity = 10);
    Inventory(const Inventory<T>& other); //복사 생성자
    ~Inventory();

    void AddItem(const T& item);
    void RemoveLastItem();
    void Assign(const Inventory<T>& other);
    void Resize(int newCapacity);
    void PrintAllItems() const;
    // 🔹 정렬 함수
    void SortItems(bool (*compare)(const T&, const T&));

    int GetSize() const;
    int GetCapacity() const;


};

// 인벤토리 생성
template <typename T>
Inventory<T>::Inventory(int capacity)
{
    if (capacity <= 0)
        capacity_ = 1;
    else
        capacity_ = capacity;

    size_ = 0;

    pItems_ = new T[capacity_];
}

// 인벤토리 소멸
template <typename T>
Inventory<T>::~Inventory()
{
    delete[] pItems_;
    pItems_ = nullptr;
}

// 인벤토리 아이템 추가
template <typename T>
void Inventory<T>::AddItem(const T& item)
{
    if (size_ >= capacity_)
    {
        Resize(capacity_ * 2);
    }

    pItems_[size_] = item;
    size_++;
}

// 인벤토리 아이템 제거
template<typename T>
void Inventory<T>::RemoveLastItem()
{
    if (size_ == 0)
    {
        std::cout << "Inventory is Empty" << std::endl;
        return;
    }

    pItems_[size_ - 1].Clear();
    size_--;
}

template <typename T>
int Inventory<T>::GetSize() const
{
    return size_;
}

template <typename T>
int Inventory<T>::GetCapacity() const
{
    return capacity_;
}

//인벤토리 아이템 출력
template <typename T>
void Inventory<T>::PrintAllItems() const
{

    if (size_ == 0)
    {
        std::cout << "Empty" << std::endl;
        return;
    }

    for (int i = 0; i < size_; i++)
    {
        std::cout << "[name: "
            << pItems_[i].GetName()
            << ", price: "
            << pItems_[i].GetPrice()
            << "G]"
            << std::endl;
    }
}

//인벤토리 깊은 복사
template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
    capacity_ = other.capacity_;
    size_ = other.size_;

    pItems_ = new T[capacity_];

    for (int i = 0; i < size_; i++)
    {
        pItems_[i] = other.pItems_[i];
    }
}

//인벤토리 깊은 복사(Assign)
template<typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
    delete[] pItems_;   // 기존 메모리 해제

    capacity_ = other.capacity_;
    size_ = other.size_;

    pItems_ = new T[capacity_];

    for (int i = 0; i < size_; i++)
    {
        pItems_[i] = other.pItems_[i];
    }
}

//인벤토리 공간 확장
template<typename T>
void Inventory<T>::Resize(int newCapacity)
{
    std::cout << "Inventory Resize: "
        << capacity_ << " -> "
        << newCapacity << std::endl;

    T* newItems = new T[newCapacity];

    for (int i = 0; i < size_; i++)
    {
        newItems[i] = pItems_[i];
    }

    delete[] pItems_;

    pItems_ = newItems;
    capacity_ = newCapacity;
}

// 정렬 함수 ( A 와 B 비교 )
template<typename T>
void Inventory<T>::SortItems(bool (*compare)(const T&, const T&))
{
    std::sort(pItems_, pItems_ + size_, compare);
}
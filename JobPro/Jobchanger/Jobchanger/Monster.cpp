#include "Monster.h"
#include "Player.h"
#include <iostream>

using namespace std;

// 생성자
Monster::Monster(string name)
{
    this->name = name;
    HP = 10;
    ATK = 30;
    DEF = 10;
}

// 몬스터 공격
void Monster::attackPlayer(Player* player)
{
    int damage = ATK - player->getDEF();

    if (damage <= 0)
    {
        damage = 1;
    }

    int newHp = player->getHP() - damage;
    player->setHP(newHp);

    cout << name << " attacks the player!" << endl;
    cout << "Damage : " << damage << endl;
    cout << "Player HP : " << player->getHP() << endl;
}

// Getter

string Monster::getName()
{
    return name;
}

int Monster::getHP()
{
    return HP;
}

int Monster::getATK()
{
    return ATK;
}

int Monster::getDEF()
{
    return DEF;
}

// Setter

void Monster::setName(string name)
{
    this->name = name;
}

void Monster::setHP(int hp)
{
    HP = hp;
}

void Monster::setATK(int atk)
{
    ATK = atk;
}

void Monster::setDEF(int def)
{
    DEF = def;
}
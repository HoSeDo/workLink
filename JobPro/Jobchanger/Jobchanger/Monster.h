#pragma once
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

class Monster
{
private:
    string name;
    int HP;
    int ATK;
    int DEF;

public:
    Monster(string name);

    void attackPlayer(Player* player);  // 이름 변경

    string getName();
    int getHP();
    int getATK();
    int getDEF();

    void setName(string name);
    void setHP(int hp);
    void setATK(int atk);
    void setDEF(int def);
};
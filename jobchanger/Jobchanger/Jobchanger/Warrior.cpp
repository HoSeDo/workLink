#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname)
{
    job_name = "Warrior";

    HP = 250;
    MP = 50;
    STR = 25;
    INT = 5;
    AGI = 10;
    DEX = 10;
    ATK = STR * 2;
    DEF = 20;
}

void Warrior::attack()
{
    cout << "Swinging the Sword!" << endl;
}
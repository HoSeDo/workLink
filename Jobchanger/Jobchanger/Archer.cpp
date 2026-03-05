#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname)
{
    job_name = "Archer";
    
    HP = 80;
    MP = 100;
    STR = 10;
    INT = 5;
    AGI = 15;
    DEX = 20;
    ATK = DEX * 2 + AGI * 1;
    DEF = 5;
}

void Archer::attack()
{
    cout << "Shoot an arrow." << endl;
}
#include "Thief.h"
#include <iostream>
using namespace std;

Thief::Thief(string nickname) : Player(nickname)
{
    job_name = "Thief";
    
    HP = 120;
    MP = 100;
    STR = 10;
    INT = 5;
    AGI = 20;
    DEX = 15;
    ATK = AGI * 2 + DEX * 1;
    DEF = 10;
}

void Thief::attack()
{
    cout << "Swinging the Dagger!" << endl;
}
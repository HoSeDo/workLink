#include "Magician.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname)
{
    job_name = "Magician";

    HP = 50;
    MP = 200;
    STR = 5;
    INT = 25;
    AGI = 10;
    DEX = 10;
    ATK = INT * 2;
    DEF = 5;
}

void Magician::attack()
{
    cout << "to memorize a spell" << endl;
}
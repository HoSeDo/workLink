#pragma once
#include <string>
#include <iostream>
using namespace std;

class Player
{
public:
    Player(string nickname);

    virtual void attack() = 0;
    void playerstat();

protected:
    string nickname;
    string job_name;
    int HP;
    int MP;
    int ATK;
    int DEF;
    int STR;
    int INT;
    int AGI;
    int DEX;
};
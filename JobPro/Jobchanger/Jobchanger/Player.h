#pragma once
#include <string>
#include <iostream>
using namespace std;

class Monster;

class Player
{
public:
    Player(string nickname);

    virtual void attack() = 0;
    void attackMonster(Monster* monster);
    void playerstat();


    // Getter
    string getNickname();
    string getJobName();
    int getHP();
    int getMP();
    int getATK();
    int getDEF();
    int getSTR();
    int getINT();
    int getAGI();
    int getDEX();

    // Setter
    void setHP(int hp);
    void setMP(int mp);
    void setATK(int atk);
    void setDEF(int def);
    void setSTR(int str);
    void setINT(int intel);
    void setAGI(int agi);
    void setDEX(int dex);

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
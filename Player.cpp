#include "Player.h"

Player::Player(string nickname)
{
    this->nickname = nickname;
    job_name = "Beginner";
    HP = 100;
    MP = 100;
    ATK = 10;
    DEF = 10;
    STR = 10;
    INT = 10;
    AGI = 10;
    DEX = 10;
}

void Player::playerstat()
{
    cout << "Nickname : " << nickname << endl;
    cout << "Job : " << job_name << endl;
    cout << "HP : " << HP << endl;
    cout << "MP : " << MP << endl;
    cout << "ATK : " << ATK << endl;
    cout << "DEF : " << DEF << endl;
    cout << "STR : " << STR << endl;
    cout << "INT : " << INT << endl;
    cout << "AGI : " << AGI << endl;
    cout << "DEX : " << DEX << endl;
}
#include "Player.h"
#include "Monster.h"

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

// 플레이어 -> 몬스터 공격
void Player::attackMonster(Monster* monster)
{
    int damage = ATK - monster->getDEF();

    if (damage <= 0)
    {
        damage = 1;
    }

    int newHP = monster->getHP() - damage;
    monster->setHP(newHP);

    cout << nickname << " attacks the monster!" << endl;
    cout << "Damage : " << damage << endl;
    cout << "Monster HP : " << monster->getHP() << endl;
}

// Getter

string Player::getNickname()
{
    return nickname;
}

string Player::getJobName()
{
    return job_name;
}

int Player::getHP()
{
    return HP;
}

int Player::getMP()
{
    return MP;
}

int Player::getATK()
{
    return ATK;
}

int Player::getDEF()
{
    return DEF;
}

int Player::getSTR()
{
    return STR;
}

int Player::getINT()
{
    return INT;
}

int Player::getAGI()
{
    return AGI;
}

int Player::getDEX()
{
    return DEX;
}

// Setter

void Player::setHP(int hp)
{
    HP = hp;
}

void Player::setMP(int mp)
{
    MP = mp;
}

void Player::setATK(int atk)
{
    ATK = atk;
}

void Player::setDEF(int def)
{
    DEF = def;
}

void Player::setSTR(int str)
{
    STR = str;
}

void Player::setINT(int intel)
{
    INT = intel;
}

void Player::setAGI(int agi)
{
    AGI = agi;
}

void Player::setDEX(int dex)
{
    DEX = dex;
}
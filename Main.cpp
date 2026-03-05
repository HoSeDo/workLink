#include <iostream>
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"

using namespace std;

int main()
{
    Player* player = nullptr;
    int choice;
    string nickname;

    cout << "닉네임을 입력하세요: ";
    cin >> nickname;

    cout << "직업을 선택하세요." << endl;
    cout << "1. 전사" << endl;
    cout << "2. 마법사" << endl;
    cout << "3. 도적" << endl;
    cout << "4. 궁수" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
        player = new Warrior(nickname);
        break;

    case 2:
        player = new Magician(nickname);
        break;

    case 3:
        player = new Thief(nickname);
        break;

    case 4:
        player = new Archer(nickname);
        break;

    default:
        cout << "잘못된 입력입니다." << endl;
        return 0;
    }

    cout << endl;
    player->playerstat();
    player->attack();

    delete player;

    return 0;
}
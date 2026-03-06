#include <iostream>
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

using namespace std;

int main()
{
    Player* player = nullptr;
    int choice;
    string nickname;

    cout << "닉네임을 입력하세요: ";
    cin >> nickname;

    cout << "<전직 시스템>" << endl;
    cout << nickname << "님, 환영합니다!" << endl;
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

    // 몬스터 생성
    Monster monster("Goblin");

    cout << endl;
    cout << "A monster appears!" << endl;

    // 몬스터 -> 플레이어 공격
    monster.attackPlayer(player);
    // 플레이어 -> 몬스터 공격
    player->attackMonster(&monster);

    delete player;

    return 0;
}
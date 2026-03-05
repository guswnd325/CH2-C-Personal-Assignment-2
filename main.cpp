#include "main.h"

int main(void)
{
	Player* player = nullptr;
	Monster* orc = new Monster("Orc", 10);
	Monster* zombie = new Monster("Zombie",50);

	cout << "1. 전사" << endl;
	cout << "2. 마법사 " << endl;
	cout << "3. 도적" << endl;
	cout << "4. 궁수" << endl;
	cout << "직업을 입력해주세요 -> ";

	int jobIdx;
	cin >> jobIdx;

	system("cls");

	if (cin.fail())
	{
		cin.clear();
		cin.ignore((std::numeric_limits<std::streamsize>().max)(), endl);
		cout << "시스템 오류 발생! 프로그램을 종료합니다.." << endl;
		return 0;
	}
	switch (jobIdx)
	{
	case 1:
		player = new Warrior();
		break;
	case 2:
		player = new Magician();
		break;
	case 3:
		player = new Thief();
		break;
	case 4:
		player = new Archer();
		break;
	default:
		cout << "시스템 오류 발생! 프로그램을 종료합니다.." << endl;
		return 0;
	}

	player->Attack();
	player->Attack(orc);
	player->Attack(zombie);
	zombie->Attack(player);
	player->Attack(zombie);
	zombie->Attack(player);

	delete player;
	delete orc;
	delete zombie;

	return 0;
}
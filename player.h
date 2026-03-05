#pragma once
#include <iostream>

class Monster;

using namespace std;

class Player
{
protected:
	string name;
	int hp, attackDamage, defensePower, speed;
public:
	// 기본 속성 및 생성자 구현
	virtual void Attack() = 0;
	Player();
	virtual ~Player();
	virtual void Attack(Monster* target);
	int GetDefensePower();
	string GetName();
	void SetHP(int value);
	void OnDamaged(Monster* target, int damage);
};
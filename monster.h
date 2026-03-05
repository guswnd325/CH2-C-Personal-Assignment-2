#pragma once
class Player;

class Monster
{
private:
	string name;
	int hp, attackDamage, defensePower, speed;

public:
	Monster(string name, int hp);

	void OnDamaged(Player* target, int damage);

	void Attack(Player* target);

	void SetHP(int value);

	string GetName();
	void SetName(string name);

	int GetAttackDamage();
	void SetAttackDamage(int attackDamage);

	int GetDefensePower();
	void SetDefensePower(int defensePower);

	int GetSpeed();
	void SetSpeed(int speed);
};

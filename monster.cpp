#include "player.h"
#include "monster.h"

Monster::Monster(string name, int hp)
{
	this->name = name;
	this->hp = hp;
	this->attackDamage = 30;
	this->defensePower = 10;
	this->speed = 10;
}

void Monster::SetHP(int value)
{
	hp = value;
}

string Monster::GetName()
{
	return name;
}

void Monster::SetName(string name)
{
	this->name = name;
}

int Monster::GetAttackDamage()
{
	return attackDamage;
}

void Monster::SetAttackDamage(int attackDamage)
{
	this->attackDamage = attackDamage;
}

int Monster::GetDefensePower()
{
	return defensePower;
}

void Monster::SetDefensePower(int defensePower)
{
	this->defensePower = defensePower;
}

int Monster::GetSpeed()
{
	return speed;
}

void Monster::SetSpeed(int speed)
{
	this->speed = speed;
}

void Monster::OnDamaged(Player* target, int damage)
{
	SetHP(hp - damage);
	if (hp <= 0)
	{
		cout << "[" << name << "]: " << target->GetName() << "의 공격으로 처치되었습니다." << endl;
	}
	else
	{
		cout << "[" << name << "]: " << target->GetName() << "으로부터 " << damage << "의 피해를 받았습니다 (남은 체력 : " << hp << ")" << endl;

	}
}

void Monster::Attack(Player* target)
{
	int damage = attackDamage - target->GetDefensePower();
	target->OnDamaged(this, damage <= 0 ? 1 : damage);
}
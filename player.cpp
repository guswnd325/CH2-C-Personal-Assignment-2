#include "player.h"
#include "monster.h"

Player::~Player()
{

}

Player::Player()
{
	name = "HyeonJoong";
	hp = 40;
	attackDamage = 30;
	defensePower = 10;
	speed = 10;
}

void Player::Attack(Monster* target)
{
	int damage = this->attackDamage - target->GetDefensePower();
	target->OnDamaged(this, damage <= 0 ? 1 : damage);
}

int Player::GetDefensePower()
{
	return defensePower;
}
string Player::GetName()
{
	return name;
}

void Player::SetHP(int value)
{
	hp = value;
}

void Player::OnDamaged(Monster* target, int damage)
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
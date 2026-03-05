#pragma once
#include "player.h"

class Monster;

class Thief : public Player
{
public:
	void Attack() override;
	void Attack(Monster* target) override;
	void SteelAttackDamage(Monster* target);
};
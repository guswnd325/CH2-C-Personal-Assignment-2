#include "thief.h"
#include "monster.h"

void Thief::Attack()
{
	cout << "[" << GetName() << "]" << "이/가 " << "공격력을 훔치고 있습니다." << endl;
}

void Thief::Attack(Monster* target)
{
	SteelAttackDamage(target);
}

void Thief::SteelAttackDamage(Monster* target)
{
	int steelValue = 5;
	int monsterAttackDamage = target->GetAttackDamage();
	int steelDamage = (monsterAttackDamage - steelValue) <= 0 ? monsterAttackDamage : steelValue;

	target->SetAttackDamage(monsterAttackDamage - steelDamage);
	attackDamage += steelDamage;
	cout << "[" << name << "]이/가 " << target->GetName() << "의 공격력을 " << steelDamage << " 훔쳤습니다(공격력 : " << attackDamage - steelDamage << " -> " << attackDamage << ")" << endl;
}
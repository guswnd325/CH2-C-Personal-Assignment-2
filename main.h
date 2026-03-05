#include <iostream>
#define endl '\n'

using namespace std;
class Player;

class Monster
{
private:
	string name;
	int hp, attackDamage, defensePower, speed;

public:
	Monster(string name, int hp)
	{
		this->name = name;
		this->hp = hp;
		attackDamage = 30;
		defensePower = 10;
		speed = 10;
	}
	void OnDamaged(Player* target, int damage);
	void Attack(Player* target);

	void SetHP(int value)
	{
		hp = value;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string name)
	{
		this->name = name;
	}

	int GetAttackDamage()
	{
		return attackDamage;
	}

	void SetAttackDamage(int attackDamage)
	{
		this->attackDamage = attackDamage;
	}

	int GetDefensePower()
	{
		return defensePower;
	}
	void SetDefensePower(int defensePower)
	{
		this->defensePower = defensePower;
	}

	int GetSpeed()
	{
		return speed;
	}
	void SetSpeed(int speed)
	{
		this->speed = speed;
	}
};


class Player
{
protected:
	string name;
	int hp, attackDamage, defensePower, speed;
public:
	// 기본 속성 및 생성자 구현
	Player()
	{
		name = "HyeonJoong";
		hp = 40;
		attackDamage = 30;
		defensePower = 10;
		speed = 10;
	}
	virtual void Attack() = 0;
	virtual ~Player() {}

	virtual void Attack(Monster* target) 
	{
		int damage = this->attackDamage - target->GetDefensePower();
		target->OnDamaged(this, damage <= 0 ? 1 : damage);
	}
	
	int GetDefensePower()
	{
		return defensePower;
	}
	string GetName()
	{
		return name;
	}

	void SetHP(int value)
	{
		hp = value;
	}

	void OnDamaged(Monster* target, int damage) 
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
	
};

class Warrior : public Player
{
public:
	void Attack() override
	{
		cout << "[" << GetName() << "]" << "이/가 " << "검을 휘둘렀습니다!" << endl;
	}
};


class Magician : public Player
{
public:
	void Attack() override
	{
		cout << "[" << GetName() << "]" << "이/가 " << "파이어볼을 날렸습니다!" << endl;
	}
};


class Thief : public Player
{
public:
	void Attack() override
	{
		cout << "[" << GetName() << "]" << "이/가 " << "공격력을 훔치고 있습니다." << endl;
	}
	void Attack(Monster* target) override
	{
		SteelAttackDamage(target);
	}
	void SteelAttackDamage(Monster* target)
	{
		int steelValue = 5;
		int monsterAttackDamage = target->GetAttackDamage();
		int steelDamage = (monsterAttackDamage - steelValue) <= 0 ? monsterAttackDamage : steelValue;

		target->SetAttackDamage(monsterAttackDamage - steelDamage);
		attackDamage += steelDamage;
		cout << "[" << name << "]이/가 " << target->GetName() << "의 공격력을 " << steelDamage << " 훔쳤습니다(공격력 : " << attackDamage-steelDamage << " -> "  << attackDamage << ")" << endl;
	}
};

class Archer : public Player
{
public:
	void Attack() override
	{
		cout << "[" << GetName() << "]" << "이/가 " << "화살을 쐈습니다!" << endl;
	}
};

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

#include <random>
#include "Player.h"
#include "Yasuo.h"
#include "TitleScientist.h"

// --------------------------------- CLASS
// --------------------------------- YASUO

// 공격 함수
void Yasuo::RandomAttack(Player* player)
{
	int randNum;
	std::random_device rd;

	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);

	randNum = dis(gen);

	if (randNum > 90)
	{
		this->SkillC(player);
	}
	else if (randNum > 75 && randNum <= 90)
	{
		this->SkillB(player);
	}
	else if (randNum > 60 && randNum <= 75)
	{
		this->SkillA(player);
	}
	else
	{
		this->Attack(player);
	}
}
bool Yasuo::Attack(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 기본 공격! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillA(Player* player)
{
	int dmg;
	int mul = 2;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 강철 폭풍 사용! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillB(Player* player)
{
	int dmg;
	int mul = 1;

	setColor(BLUE);
	std::cout << " [ " << this->GetName()
		<< "이(가) 바람장막 사용! (쉴드+50: 2턴) ]" << std::endl;

	this->SetShield(this->GetShield() + 50);
	this->SetShieldCnt(this->GetShieldCnt() + 2);

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}
bool Yasuo::SkillC(Player* player)
{
	int dmg;
	int mul = 6;

	setColor(BLUE);
	std::cout << " [ " << this->GetName() << "이(가) "
		<< player->GetName() << "에게 우리에게돈!!! ]" << std::endl;

	dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
		- (player->GetDef() + player->GetDefBuff()));
	if (dmg < 0) dmg = 0;

	player->SetHp(player->GetHp() - dmg);
	this->TurnManager();

	return true;
}

// 기능 함수
void Yasuo::DropItem(Player* player)
{
	setColor(SKYBLUE);
	std::cout << " [ 칭호: 과학자를 얻었다! ]" << std::endl;
	std::cout << " [ " << this->GetDropGold() << " 골드를 얻었다! ]" << std::endl;
	std::cout << " [ 인벤토리를 확인해보자! ]" << std::endl;
	player->AddItem(new TitleScientist());
	player->SetGold(player->GetGold() + this->GetDropGold());
}
#pragma once
#include "Character.h"

class Player;

// 몬스터 타입 목록
enum MyMonsterType
{
    ENUM_MONSTER_LUX,
    ENUM_MONSTER_VAYNE,
    ENUM_MONSTER_MASTERYI,
    ENUM_MONSTER_YASUO
};

// --------------------------------- CLASS
// --------------------------------- MONSTER
class Monster : public Character
{
private:
    int dropGold;

public:
    // 생성자
    Monster()
    {
        this->SetDropGold(0);
    }
    Monster(std::string _name) : Monster()
    {
        this->SetName(_name);
    }

    // 공격 함수
    virtual void RandomAttack(Player* player);
    virtual bool Attack(Player* player);
    virtual bool SkillA(Player* player);
    virtual bool SkillB(Player* player);
    virtual bool SkillC(Player* player);

    // 기능 함수
    virtual void PrintInfo();
    virtual void DropItem(Player* player);

    // get
    virtual int GetDropGold();

    // set
    virtual void SetDropGold(int _dropGold);
};
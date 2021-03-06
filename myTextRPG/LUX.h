#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- LUX
class Player;

class LUX : public Monster
{
private:

public:
    // 생성자
    LUX()
    {
        this->SetHp(70);
        this->SetDmg(7);
        this->SetDef(0);
        this->SetDropGold(100);
        this->SetName("럭스");
    }

    // 공격 함수
    void RandomAttack(Player* player);
    bool Attack(Player* player);
    bool SkillA(Player* player);
    bool SkillB(Player* player);
    bool SkillC(Player* player);

    // 기능함수
    void DropItem(Player* player);
};
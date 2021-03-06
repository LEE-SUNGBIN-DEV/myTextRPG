#include "Wizard.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- WIZARD

// 공격 함수
bool Wizard::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    setColor(RED);
    std::cout << " [ " << this->GetName() << "이(가) "
        << monster->GetName() << "에게 기본 공격! ]" << std::endl;

    dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
        - (monster->GetDef() + monster->GetDefBuff()));
    if (dmg < 0) dmg = 0;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Wizard::SkillA(Monster* monster)
{
    int dmg;
    int mul = 2;
    int needMana = 20;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << " [ 마나가 부족합니다. ]" << std::endl;
        return false;
    }
    else
    {
        std::cout << " [ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 파이어 볼 사용! ]" << std::endl;

        dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
            - (monster->GetDef() + monster->GetDefBuff()));
        if (dmg < 0) dmg = 0;

        this->SetMp(this->GetMp() - needMana);
        monster->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }

}
bool Wizard::SkillB(Monster* monster)
{
    int dmg;
    int mul = 1;
    int needMana = 30;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << " [ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << " [ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 아이스 스피어 사용! (빙결: 2턴) ]" << std::endl;

        dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
            - (monster->GetDef() + monster->GetDefBuff()));
        if (dmg < 0) dmg = 0;

        monster->SetStunCnt(2);
        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
bool Wizard::SkillC(Monster* monster)
{
    int dmg;
    int mul = 5;
    int needMana = 50;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << " [ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << " [ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 메테오 사용!] " << std::endl;

        dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
            - (monster->GetDef() + monster->GetDefBuff()));
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}


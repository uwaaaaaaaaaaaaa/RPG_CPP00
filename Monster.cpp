#include "Monster.h"

// コンストラクタ
Monster::Monster(
    int hp ,
    int maxHp ,
    int mp ,
    int maxMp ,
    int attack ,
    const std::string &name ,
    const std::string &aa
)
    : Character(
        hp ,
        maxHp ,
        mp ,
        maxMp ,
        attack ,
        name ,
        aa
    ){}

// 攻撃
void Monster::Attack(){
    Character::Attack();
}

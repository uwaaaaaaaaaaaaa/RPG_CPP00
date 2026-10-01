#pragma once

#include "Character.h"

// モンスタークラス
class Monster : public Character{
    public:

    // コンストラクタ
    Monster(
        int hp ,
        int maxHp ,
        int mp ,
        int maxMp ,
        int attack ,
        const std::string &name ,
        const std::string &aa
    );

    // デストラクタ
    virtual ~Monster() = default;

    // 攻撃
    void Attack() override;
};

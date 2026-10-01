#pragma once

#include "Monster.h"

// スライムクラス
class Slime : public Monster{
    public:

    // コンストラクタ
    Slime();

    // 攻撃
    void Attack() override;
};

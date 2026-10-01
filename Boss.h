#pragma once

#include "Monster.h"

// 魔王クラス
class Boss : public Monster{
    public:

    // コンストラクタ
    Boss();

    // 攻撃
    void Attack() override;
};

#pragma once

#include "Character.h"

// プレイヤークラス
class Player : public Character{
    public:

    // コンストラクタ
    Player();

    // 攻撃
    void Attack() override;

    // 呪文
    void Spell() override;

    // 逃げる
    void Run() override;
};

#include "Player.h"

// コンストラクタの定義で、継承元のコンストラクタを呼んでいる
Player::Player()
    : Character(
        100 ,        // HP
        100 ,        // 最大HP
        15 ,         // MP
        15 ,         // 最大MP
        30 ,         // 攻撃力
        "ゆうしゃ" , // 名前
        ""          // アスキーアート
    ){}

// 攻撃
void Player::Attack(){
    Character::Attack();
}

// 呪文
void Player::Spell(){
    Character::Spell();
}

// 逃げる
void Player::Run(){
    Character::Run();
}

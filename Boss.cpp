#include "Boss.h"

// コンストラクタの定義で、継承元のコンストラクタを呼んでいる
Boss::Boss()
    : Monster(
        255 ,             // HP
        255 ,             // 最大HP
        0 ,               // MP
        0 ,               // 最大MP
        50 ,              // 攻撃力
        "まおう" ,        // 名前
        "　　Ａ＠Ａ\n"
        "ψ（▼皿▼）ψ"   // アスキーアート
    ){}

// 攻撃
void Boss::Attack(){
    Monster::Attack();
}

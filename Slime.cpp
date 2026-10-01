#include "Slime.h"

// コンストラクタの定義で、継承元のコンストラクタを呼んでいる
Slime::Slime()
    : Monster(
        3 ,              // HP
        3 ,              // 最大HP
        0 ,              // MP
        0 ,              // 最大MP
        2 ,              // 攻撃力
        "スライム" ,     // 名前
        "／・Д・＼\n"
        "～～～～～"    // アスキーアート
    ){}

// 攻撃
void Slime::Attack(){
    Monster::Attack();
}

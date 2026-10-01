#include "Character.h"

#include <iostream>
#include <cstdlib>

namespace{
    constexpr int SpellCost = 3;
}

// コンストラクタ
Character::Character(
    int hp ,
    int maxHp ,
    int mp ,
    int maxMp ,
    int attack ,
    const std::string &name ,
    const std::string &aa
)
    //()内を代入して初期化している
    : hp( hp ) ,
    maxHp( maxHp ) ,
    mp( mp ) ,
    maxMp( maxMp ) ,
    attack( attack ) ,
    name( name ) ,
    aa( aa ) ,
    command( Command::Fight ) ,
    target( nullptr ){}

// ステータス表示
void Character::Draw() const{
    std::cout 
        << "ＨＰ：" 
        << hp << "／" 
        << maxHp 
        << "　ＭＰ：" 
        << mp << "／" 
        << maxMp 
        << "\n";
}

// 攻撃
void Character::Attack(){
    if( target == nullptr ){
        return;
    }

    std::cout << name << "の　こうげき！\n";

    int damage = 1 + std::rand() % attack;

    target->TakeDamage( damage );

    std::cout << target->GetName() << "に　" << damage << "の　ダメージ！\n";
}

// 呪文
void Character::Spell(){
    if( mp < SpellCost ){
        std::cout << "ＭＰが　たりない！\n";

        return;
    }

    mp -= SpellCost;

    std::cout << name << "は　ヒールを　となえた！\n";

    Heal();

    std::cout << name << "のきずが　かいふくした！\n";
}

// 逃げる
void Character::Run(){
    std::cout << name << "は　にげだした！\n";
}

// ダメージを受ける
void Character::TakeDamage( int damage ){
    hp -= damage;

    if( hp < 0 ){
        hp = 0;
    }
}

// HPを最大まで回復
void Character::Heal(){
    hp = maxHp;
}

// 生存確認
bool Character::IsAlive() const{
    return hp > 0;
}

// 名前を取得
const std::string &Character::GetName() const{
    return name;
}

// アスキーアートを取得
const std::string &Character::GetAA() const{
    return aa;
}

// HPを取得
int Character::GetHp() const{
    return hp;
}

// 最大HPを取得
int Character::GetMaxHp() const{
    return maxHp;
}

// MPを取得
int Character::GetMp() const{
    return mp;
}

// 最大MPを取得
int Character::GetMaxMp() const{
    return maxMp;
}

// 攻撃力を取得
int Character::GetAttack() const{
    return attack;
}

// コマンドを設定
void Character::SetCommand( Command command ){
    this->command = command;
}

// コマンドを取得
Command Character::GetCommand() const{
    return command;
}

// 攻撃対象を設定
void Character::SetTarget( Character *target ){
    this->target = target;
}

// 攻撃対象を取得
Character *Character::GetTarget() const{
    return target;
}

#pragma once

#include <string>
#include "Command.h"

// キャラクターの基底クラス
class Character{
    protected:

    // HP
    int hp;
    int maxHp;

    // MP
    int mp;
    int maxMp;

    // 攻撃力
    int attack;

    // 名前
    std::string name;

    // アスキーアート
    std::string aa;

    // コマンド
    Command command;

    // 攻撃対象
    Character *target;

    public:

    // コンストラクタ
    Character(
        int hp ,
        int maxHp ,
        int mp ,
        int maxMp ,
        int attack ,
        const std::string &name ,
        const std::string &aa
    );

    // デストラクタ
    virtual ~Character() = default;

    // ステータス表示
    virtual void Draw() const;

    // 攻撃
    virtual void Attack();

    // 呪文
    virtual void Spell();

    // 逃げる
    virtual void Run();

    // ダメージを受ける
    void TakeDamage( int damage );

    // HP回復
    void Heal();

    // 生存確認
    bool IsAlive() const;

    // 名前を取得
    const std::string &GetName() const;

    // アスキーアートを取得
    const std::string &GetAA() const;

    // HPを取得
    int GetHp() const;

    // 最大HPを取得
    int GetMaxHp() const;

    // MPを取得
    int GetMp() const;

    // 最大MPを取得
    int GetMaxMp() const;

    // 攻撃力を取得
    int GetAttack() const;

    // コマンドを設定
    void SetCommand( Command command );

    // コマンドを取得
    Command GetCommand() const;

    // 攻撃対象を設定
    void SetTarget( Character *target );

    // 攻撃対象を取得
    Character *GetTarget() const;
};

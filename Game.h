#pragma once

#include <memory>

#include "Player.h"
#include "Monster.h"

// ゲームクラス
class Game{
    private:

    // プレイヤー
    std::unique_ptr<Player> player;

    // モンスター
    std::unique_ptr<Monster> monster;

    public:

    // コンストラクタ
    Game();

    // ゲーム開始
    void Run();

    private:

    // 初期化
    void Init();

    // 戦闘
    void Battle( std::unique_ptr<Monster> monster );

    // 戦闘画面を描画
    void DrawBattleScreen() const;

    // コマンドを選択
    void SelectCommand();

    // コマンドを実行
    void ExecuteCommand( Character &character );

    // キー入力
    char GetKey() const;

    // キー入力待ち
    void WaitKey() const;

    // 画面をクリア
    void ClearScreen() const;
};

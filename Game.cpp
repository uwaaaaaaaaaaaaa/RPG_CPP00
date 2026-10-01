#include "Game.h"

#include "Slime.h"
#include "Boss.h"

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

// コンストラクタ
Game::Game(){

    //関数を呼ぶと同時にランダムシードを設定
    std::srand( static_cast<unsigned int>( std::time( nullptr ) ) );

    Init();
}

// 初期化
void Game::Init(){
    player = std::make_unique<Player>();
}

// ゲーム開始
void Game::Run(){
    // スライムとの戦闘
    Battle( std::unique_ptr<Monster>( new Slime() ) );

    /*
    // 魔王と戦わせたい場合
    Battle( std::unique_ptr<Monster>( new Boss() ) );
    */
}

// 戦闘
void Game::Battle( std::unique_ptr<Monster> monster ){

    this->monster = std::move( monster );

    // プレイヤーの攻撃対象をモンスターに設定
    player->SetTarget( this->monster.get() );

    // モンスターの攻撃対象をプレイヤーに設定
    this->monster->SetTarget( player.get() );

    ClearScreen();

    DrawBattleScreen();

    std::cout << this->monster->GetName() << "があらわれた！\n";

    WaitKey();

    while( player->IsAlive() && this->monster->IsAlive() ){
        // プレイヤーのコマンドを選択
        SelectCommand();

        // プレイヤーの行動
        ExecuteCommand( *player );

        // プレイヤーが逃げた場合
        if( player->GetCommand() == Command::Run ){
            return;
        }

        // モンスターが倒された場合
        if( !this->monster->IsAlive() ){
            break;
        }

        // モンスターの行動
        this->monster->SetCommand( Command::Fight );

        ExecuteCommand( *this->monster );

        // プレイヤーが倒された場合
        if( !player->IsAlive() ){
            break;
        }
    }

    // 戦闘終了
    ClearScreen();

    DrawBattleScreen();

    if( !player->IsAlive() ){
        std::cout << "あなたは　しにました\n";
    }
    else if( !this->monster->IsAlive() ){
        std::cout << this->monster->GetName() << "を　たおした！\n";
    }

    WaitKey();
}

// 戦闘画面
void Game::DrawBattleScreen() const{
    ClearScreen();

    // プレイヤー
    std::cout << player->GetName() << "\n";

    player->Draw();

    std::cout << "\n";

    // モンスター
    if( monster ){
        std::cout << monster->GetAA();

        std::cout << "（ＨＰ：" << monster->GetHp() << "／" << monster->GetMaxHp() << "）\n";
    }

    std::cout << "\n";
}

// コマンドを選択
void Game::SelectCommand(){
    int selected = 0;

    while( true ){
        DrawBattleScreen();

        // たたかう
        std::cout << ( selected == 0 ? "＞" : "　" ) << "たたかう\n";

        // じゅもん
        std::cout << ( selected == 1 ? "＞" : "　" ) << "じゅもん\n";

        // にげる
        std::cout << ( selected == 2 ? "＞" : "　" ) << "にげる\n";

        char key = GetKey();

        switch( key ){
            case 'w':
            case 'W':

                selected--;

                break;

            case 's':
            case 'S':

                selected++;

                break;

            default:

                if( selected == 0 ){
                    player->SetCommand( Command::Fight );
                }
                else if( selected == 1 ){
                    player->SetCommand( Command::Spell );
                }
                else{
                    player->SetCommand( Command::Run );
                }

                return;
        }

        // 上下をループ
        if( selected < 0 ){
            selected = 2;
        }

        if( selected > 2 ){
            selected = 0;
        }
    }
}

// コマンドを実行
void Game::ExecuteCommand( Character &character ){
    DrawBattleScreen();

    switch( character.GetCommand() ){
        case Command::Fight:

            character.Attack();

            break;

        case Command::Spell:

            character.Spell();

            break;

        case Command::Run:

            character.Run();

            break;
    }

    WaitKey();
}

// キー入力
char Game::GetKey() const{
    return _getch();
}

// キー入力待ち
void Game::WaitKey() const{
    _getch();
}

// 画面をクリア
void Game::ClearScreen() const{
    system( "cls" );
}

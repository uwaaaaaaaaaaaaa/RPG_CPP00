ファイル構成

RPGGame/
│
├─ main.cpp
│
├─ Command.h
│
├─ Character.h
├─ Character.cpp
│
├─ Player.h
├─ Player.cpp
│
├─ Monster.h
├─ Monster.cpp
│
├─ Slime.h
├─ Slime.cpp
│
├─ Boss.h
├─ Boss.cpp
│
├─ Game.h
└─ Game.cpp





クラスの関係はこうします。

                    Character
                        │
              ┌─────────┴─────────┐
              │                   │
            Player             Monster
                                  │
                         ┌────────┴────────┐
                         │                 │
                       Slime              Boss

#ifndef GAME_H_
#define GAME_H_

#include "character.h"
#include "game_constant.h"
#include "map_system.h"

class Game
{
  public:
    Game();
    Game(Game &&) = default;
    Game(const Game &) = default;
    Game &operator=(Game &&) = default;
    Game &operator=(const Game &) = default;
    ~Game();

    // 开始运行
    void Run();
    // 暂停
    void Pause();

  private:
    GameStatus status;
    MapSystem *mapSystem;
    Character *character;

    void HandlerEvent();
    void Draw();
};

#endif // !GAME_H_
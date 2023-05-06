#ifndef GAME_H_
#define GAME_H_

#include "abstract_character.h"
#include "game_config.h"
#include "map_system.h"

class Game
{
  public:
    Game(GameConfig config);
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
    GameConfig config;
    MapSystem *mapSystem;
    Character *character;

    void Update();
    void HandlerEvent();
    void Draw();
};

#endif // !GAME_H_
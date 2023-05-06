#ifndef GAME_CONFIG_H_
#define GAME_CONFIG_H_
enum GameStatus
{
    // 运行
    RUNNING,
    // 暂停
    PAUSE,
};

enum FileType
{
    TMX,
    PHOTO,
};

enum ResourceType
{
    MAP,
    CHARACTER,
};

class GameConfig
{
  public:
    GameConfig();
    GameConfig(char *title, int screenWidth, int screenHeight);
    GameConfig(GameConfig &&) = default;
    GameConfig(const GameConfig &) = default;
    GameConfig &operator=(GameConfig &&) = default;
    GameConfig &operator=(const GameConfig &) = default;
    ~GameConfig();

    char *GetTitle();
    int GetScreenWidth();
    int GetScreenHeight();

  private:
    char *title;
    int screenWidth;
    int screenHeight;
};

#endif // !GAME_CONFIG_H_
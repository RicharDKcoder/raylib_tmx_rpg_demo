#include "game.h"
#include <iostream>
int main()
{
    GameConfig gameConfig{(char *)"game", 960, 640};
    Game *game = new Game(gameConfig);
    game->Run();
    return 0;
}
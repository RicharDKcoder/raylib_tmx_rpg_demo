#include "game_config.h"

GameConfig::GameConfig()
{
    this->title = (char *)"undefine window";
    this->screenWidth = 960;
    this->screenHeight = 640;
}

GameConfig::GameConfig(char *title, int screenWidth, int screenHeight)
{
    this->title = title;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

GameConfig::~GameConfig()
{
}

char *GameConfig::GetTitle()
{
    return this->title;
}

int GameConfig::GetScreenWidth()
{
    return this->screenWidth;
}

int GameConfig::GetScreenHeight()
{
    return this->screenHeight;
}
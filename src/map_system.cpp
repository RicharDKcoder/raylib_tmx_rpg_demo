#include "map_system.h"
#define RAYLIB_TMX_IMPLEMENTATION
#include "raylib-tmx.h"

MapSystem::MapSystem()
{
    this->mapResourceList.push_back((char *)"resources/background.tmx");
    this->curMapIndex = 0;
    this->curMap = LoadTMX(this->mapResourceList.at(this->curMapIndex));
}

MapSystem::~MapSystem()
{
    delete this->curMap;
}

void MapSystem::Draw()
{
    DrawTMX(this->curMap, 0, 0, WHITE);
}

void MapSystem::ChangeToPre()
{
    tmx_map *oldMap = this->curMap;
    // 加载新资源 并赋值
    char *preMapFile = this->mapResourceList.at(--this->curMapIndex);
    this->curMap = LoadTMX(preMapFile);
    // 卸载旧资源
    UnloadTMX(oldMap);
}

void MapSystem::ChangeToNext()
{
    tmx_map *oldMap = this->curMap;
    // 加载新资源 并赋值
    char *nextMapFile = this->mapResourceList.at(++this->curMapIndex);
    this->curMap = LoadTMX(nextMapFile);
    // 卸载旧资源
    UnloadTMX(oldMap);
}
#include "map_system.h"
#define RAYLIB_TMX_IMPLEMENTATION
#include "raylib-tmx.h"

MapSystem::MapSystem()
{
    MapResource mapResource = MapResource{(char *)"resources/background.tmx", 8, 8, 8, 8};
    this->mapResourceList.push_back(&mapResource);
    this->curMapIndex = 0;
    this->curMap = LoadTMX(this->mapResourceList.at(this->curMapIndex)->tmxMapFile);
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
    MapResource *curMapResource = this->mapResourceList.at(--this->curMapIndex);
    const char *preMapFile = curMapResource->tmxMapFile;
    this->curMap = LoadTMX(preMapFile);
    this->curMapResource = curMapResource;
    // 卸载旧资源
    UnloadTMX(oldMap);
}

void MapSystem::ChangeToNext()
{
    tmx_map *oldMap = this->curMap;
    // 加载新资源 并赋值
    MapResource *curMapResource = this->mapResourceList.at(++this->curMapIndex);
    const char *nextMapFile = curMapResource->tmxMapFile;
    this->curMap = LoadTMX(nextMapFile);
    this->curMapResource = curMapResource;
    // 卸载旧资源
    UnloadTMX(oldMap);
}

MapResource *MapSystem::GetCurMapResource()
{
    return this->curMapResource;
}
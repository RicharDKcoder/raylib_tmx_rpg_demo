#ifndef MAP_SYSTEM_H_
#define MAP_SYSTEM_H_

#include "game_config.h"
#include "tmx.h"
#include <vector>

typedef struct MapResource
{
    const char *tmxMapFile;
    // 当前地图的属性
    const int mapBorderTop;
    const int mapBorderBottom;
    const int mapBorderLeft;
    const int mapBorderRight;

} MapResource;

class MapSystem
{
  public:
    MapSystem();
    MapSystem(MapSystem &&) = default;
    MapSystem(const MapSystem &) = default;
    MapSystem &operator=(MapSystem &&) = default;
    MapSystem &operator=(const MapSystem &) = default;
    ~MapSystem();

    // 绘制当前地图
    void Draw();
    // 切换上一个地图场景
    void ChangeToPre();
    // 切换下一个地图场景
    void ChangeToNext();

    // 当前地图的属性
    MapResource *GetCurMapResource();

  private:
    // 所有地图资源路径
    std::vector<MapResource *> mapResourceList;
    // 当前绘制的地图资源
    int curMapIndex;
    MapResource *curMapResource;
    tmx_map *curMap;
};

#endif // !MAP_SYSTEM_H_
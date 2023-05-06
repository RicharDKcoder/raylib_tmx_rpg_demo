#ifndef MAP_SYSTEM_H_
#define MAP_SYSTEM_H_

#include "game_constant.h"
#include "tmx.h"
#include <vector>

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

  private:
    // 所有地图资源路径
    std::vector<char *> mapResourceList;
    // 当前绘制的地图资源
    int curMapIndex;
    tmx_map *curMap;
};

#endif // !MAP_SYSTEM_H_
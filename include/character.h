#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "animation.h"
#include <raylib.h>

enum AnimationStatus
{
    IDLE,
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class Character
{
  public:
    Character();
    Character(Character &&) = default;
    Character(const Character &) = default;
    Character &operator=(Character &&) = default;
    Character &operator=(const Character &) = default;
    virtual ~Character();

    // 更新
    virtual void Update() = 0;
    // 事件
    void HandlerEvent();
    // 绘图
    void Draw();

    // 移动
    virtual void Up() = 0;
    virtual void Down() = 0;
    virtual void Left() = 0;
    virtual void Right() = 0;

  protected:
    AnimationStatus animationStatus;
    // 位置
    Vector2 *point;
    // 移动速度
    int moveSpeed;
    // 动画
    Animation *idleAnimation;
    Animation *upAnimation;
    Animation *downAnimation;
    Animation *leftAnimation;
    Animation *rightAnimation;

  private:
};

#endif // !CHARACTER_H_
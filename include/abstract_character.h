#ifndef ABSTRACT_CHARACTER_H_
#define ABSTRACT_CHARACTER_H_

#include "animation.h"
#include <raylib.h>

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
    virtual void HandlerEvent() = 0;
    // 绘图
    virtual void Draw() = 0;

  protected:
    // 位置
    Vector2 *point;
    // 移动速度
    int moveSpeed;

    // 移动
    void Up();
    void Down();
    void Left();
    void Right();

  private:
};

#endif // !ABSTRACT_CHARACTER_H_
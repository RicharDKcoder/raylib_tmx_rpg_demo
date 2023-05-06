#ifndef NINJA_CHARACTER_H_
#define NINJA_CHARACTER_H_
#include "abstract_character.h"
#include <raylib.h>

enum NinjaCharacterStatus
{
    IDLE = 1 << 0,
    RUN_LEFT = 1 << 1,
    RUN_RIGHT = 1 << 2,
    JUMP = 1 << 3,
    DOUBLE_JUMP = 1 << 4,
    WALL_JUMP = 1 << 5,
    FALL = 1 << 6,
    HIT = 1 << 7,
};

typedef struct JumpData
{
    Vector2 point;
    float maxHeight;
    float curHeight;
    float jumpSpeed;
    float fallSpeed;
} JumpData;

class NinjaCharacter : public Character
{
  public:
    NinjaCharacter();
    NinjaCharacter(NinjaCharacter &&) = default;
    NinjaCharacter(const NinjaCharacter &) = default;
    NinjaCharacter &operator=(NinjaCharacter &&) = default;
    NinjaCharacter &operator=(const NinjaCharacter &) = default;
    ~NinjaCharacter();

    void Update();
    void HandlerEvent();
    void Draw();
    // 移动
    void Jump();
    void Fall();

  private:
    JumpData jumpData;
    int status;
    AnimationDirection direction;
    // 动画
    Animation *doubleJumpAnimation;
    Animation *fallAnimation;
    Animation *hitAnimation;
    Animation *idleAnimation;
    Animation *jumpAnimation;
    Animation *runAnimation;
    Animation *wallJumpAnimation;
};

#endif // !NINJA_CHARACTER_H_
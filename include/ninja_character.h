#ifndef NINJA_CHARACTER_H_
#define NINJA_CHARACTER_H_
#include "character.h"
class NinjaCharacter : public Character
{
  public:
    NinjaCharacter();
    NinjaCharacter(NinjaCharacter &&) = default;
    NinjaCharacter(const NinjaCharacter &) = default;
    NinjaCharacter &operator=(NinjaCharacter &&) = default;
    NinjaCharacter &operator=(const NinjaCharacter &) = default;
    ~NinjaCharacter();

    // 更新
    void Update();
    void HandlerEvent();
    // 移动
    void Up();
    void Down();
    void Left();
    void Right();

  private:
};

#endif // !NINJA_CHARACTER_H_
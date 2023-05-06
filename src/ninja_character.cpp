#include "ninja_character.h"
#include "animation.h"
#include <cstddef>
#include <raylib.h>

NinjaCharacter::NinjaCharacter()
{
    this->idleAnimation =
        new Animation((char *)"resources/Main Characters/Ninja Frog/Idle (32x32).png", this->point, 32, 32, 11, 0.1);
}

NinjaCharacter::~NinjaCharacter()
{
}

// 更新
void NinjaCharacter::Update()
{
}

void NinjaCharacter::Up()
{
}
void NinjaCharacter::Down()
{
}
void NinjaCharacter::Left()
{
}
void NinjaCharacter::Right()
{
}

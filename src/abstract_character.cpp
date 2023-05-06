#include "abstract_character.h"
#include <iostream>
#include <raylib.h>

Character::Character()
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    this->point = new Vector2{float(screenWidth) / 2, float(screenHeight) / 2};
    this->moveSpeed = 0;
}

Character::~Character()
{
}

void Character::Up()
{
    float lastFrameTime = GetFrameTime();
    this->point->y -= lastFrameTime * this->moveSpeed;
}
void Character::Down()
{
    float lastFrameTime = GetFrameTime();
    this->point->y += lastFrameTime * this->moveSpeed;
}
void Character::Left()
{
    float lastFrameTime = GetFrameTime();
    this->point->x -= lastFrameTime * this->moveSpeed;
}
void Character::Right()
{
    float lastFrameTime = GetFrameTime();
    this->point->x += lastFrameTime * this->moveSpeed;
}
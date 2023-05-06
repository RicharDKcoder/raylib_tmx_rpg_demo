#include "character.h"
#include <iostream>
#include <raylib.h>

Character::Character()
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    this->point = new Vector2{float(screenWidth) / 2, float(screenHeight) / 2};
    this->animationStatus = AnimationStatus::IDLE;
}

Character::~Character()
{
}

void Character::Update()
{
}

void Character::HandlerEvent()
{
    if (IsKeyDown(KEY_UP))
    {
        this->Up();
    }
    if (IsKeyDown(KEY_DOWN))
    {
        this->Down();
    }
    if (IsKeyDown(KEY_LEFT))
    {
        this->Left();
    }
    if (IsKeyDown(KEY_RIGHT))
    {
        this->Right();
    }
}

void Character::Draw()
{
    std::cout << "character status: " << this->animationStatus << std::endl;
    switch (this->animationStatus)
    {
    case AnimationStatus::IDLE:
        this->idleAnimation->Play();
        break;
    case AnimationStatus::UP:
        this->upAnimation->Play();
        break;
    case AnimationStatus::DOWN:
        this->downAnimation->Play();
        break;
    case AnimationStatus::LEFT:
        this->leftAnimation->Play();
        break;
    case AnimationStatus::RIGHT:
        this->rightAnimation->Play();
        break;
    default:
        break;
    }
    // this->animationStatus = AnimationStatus::IDLE;
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
#include "ninja_character.h"
#include "animation.h"
#include "raylib.h"
#include <algorithm>
#include <bitset>
#include <cstddef>
#include <iostream>

NinjaCharacter::NinjaCharacter()
{
    this->status = NinjaCharacterStatus::IDLE;
    this->direction = AnimationDirection::RIGHT;
    this->moveSpeed = 80;
    this->jumpData.maxHeight = 64;
    this->jumpData.curHeight = 0;
    this->jumpData.jumpSpeed = 160;
    this->jumpData.fallSpeed = 160;
    this->doubleJumpAnimation = new Animation((char *)"resources/Main Characters/Ninja Frog/Double Jump (32x32).png",
                                              this->point, 32, 32, 6, 0.05);
    this->fallAnimation =
        new Animation((char *)"resources/Main Characters/Ninja Frog/Fall (32x32).png", this->point, 32, 32, 1, 0.05);
    this->hitAnimation =
        new Animation((char *)"resources/Main Characters/Ninja Frog/Hit (32x32).png", this->point, 32, 32, 7, 0.05);
    this->idleAnimation =
        new Animation((char *)"resources/Main Characters/Ninja Frog/Idle (32x32).png", this->point, 32, 32, 11, 0.05);
    this->jumpAnimation =
        new Animation((char *)"resources/Main Characters/Ninja Frog/Jump (32x32).png", this->point, 32, 32, 1, 0.05);
    this->runAnimation =
        new Animation((char *)"resources/Main Characters/Ninja Frog/Run (32x32).png", this->point, 32, 32, 12, 0.05);
    this->wallJumpAnimation = new Animation((char *)"resources/Main Characters/Ninja Frog/Wall Jump (32x32).png",
                                            this->point, 32, 32, 5, 0.05);
}

NinjaCharacter::~NinjaCharacter()
{
}

void NinjaCharacter::Update()
{
    std::cout << "NinjaCharacterStatus: " << std::bitset<8>(this->status) << std::endl;
    if (this->status & NinjaCharacterStatus::DOUBLE_JUMP)
    {
    }
    if (this->status & NinjaCharacterStatus::FALL)
    {
        this->Fall();
    }
    if (this->status & NinjaCharacterStatus::HIT)
    {
    }
    if (this->status & NinjaCharacterStatus::IDLE)
    {
    }
    if (this->status & NinjaCharacterStatus::JUMP)
    {

        this->Jump();
    }
    if (this->status & NinjaCharacterStatus::RUN_LEFT)
    {
        this->direction = AnimationDirection::LEFT;
        this->Left();
    }
    if (this->status & NinjaCharacterStatus::RUN_RIGHT)
    {
        this->direction = AnimationDirection::RIGHT;
        this->Right();
    }
    if (this->status & NinjaCharacterStatus::WALL_JUMP)
    {
    }
}

void NinjaCharacter::HandlerEvent()
{
    if (!(this->status & NinjaCharacterStatus::JUMP || this->status & NinjaCharacterStatus::FALL) &&
        IsKeyPressed(KEY_UP))
    {
        this->jumpData.point = Vector2{this->point->x, this->point->y};
        this->status = this->status ^ NinjaCharacterStatus::IDLE | NinjaCharacterStatus::JUMP;
    }
    // if (IsKeyDown(KEY_DOWN))
    // {
    //     this->status = this->status ^ NinjaCharacterStatus::IDLE | NinjaCharacterStatus::FALL;
    // }

    if (IsKeyDown(KEY_LEFT))
    {
        this->status = this->status ^ NinjaCharacterStatus::IDLE | NinjaCharacterStatus::RUN_LEFT;
    }

    if (IsKeyDown(KEY_RIGHT))
    {
        this->status = this->status ^ NinjaCharacterStatus::IDLE | NinjaCharacterStatus::RUN_RIGHT;
    }

    if (IsKeyUp(KEY_LEFT) && this->status & NinjaCharacterStatus::RUN_LEFT)
    {
        this->status = this->status ^ NinjaCharacterStatus::RUN_LEFT;
    }
    if (IsKeyUp(KEY_RIGHT) && this->status & NinjaCharacterStatus::RUN_RIGHT)
    {
        this->status = this->status ^ NinjaCharacterStatus::RUN_RIGHT;
    }
    if (this->status <= 1)
    {
        this->status = NinjaCharacterStatus::IDLE;
    }
}

void NinjaCharacter::Draw()
{
    std::cout << "direction: " << this->direction << std::endl;
    if (this->status & NinjaCharacterStatus::HIT)
    {
        if (NULL != this->hitAnimation)
        {
            this->hitAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::DOUBLE_JUMP)
    {
        if (NULL != this->doubleJumpAnimation)
        {
            this->doubleJumpAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::JUMP)
    {

        if (NULL != this->jumpAnimation)
        {
            this->jumpAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::WALL_JUMP)
    {
        if (NULL != this->wallJumpAnimation)
        {
            this->wallJumpAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::FALL)
    {
        if (NULL != this->fallAnimation)
        {
            this->fallAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::RUN_LEFT)
    {
        if (NULL != this->runAnimation)
        {
            this->runAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::RUN_RIGHT)
    {
        if (NULL != this->runAnimation)
        {
            this->runAnimation->Play(this->direction);
        }
    }
    else if (this->status & NinjaCharacterStatus::IDLE)
    {

        if (NULL != this->idleAnimation)
        {
            this->idleAnimation->Play(this->direction);
        }
    }
    else
    {
        if (NULL != this->idleAnimation)
        {
            this->idleAnimation->Play(this->direction);
        }
    }
    // this->animationStatus = AnimationStatus::IDLE;
}

void NinjaCharacter::Jump()
{
    float lastFrameTime = GetFrameTime();
    this->jumpData.curHeight += lastFrameTime * this->jumpData.jumpSpeed;
    this->jumpData.curHeight = std::min(this->jumpData.curHeight, this->jumpData.maxHeight);
    this->point->y = this->jumpData.point.y - this->jumpData.curHeight;
    if (this->jumpData.curHeight >= this->jumpData.maxHeight)
    {
        this->status = this->status ^ NinjaCharacterStatus::JUMP | NinjaCharacterStatus::FALL;
    }
}

void NinjaCharacter::Fall()
{
    float lastFrameTime = GetFrameTime();
    this->jumpData.curHeight -= lastFrameTime * this->jumpData.fallSpeed;
    this->jumpData.curHeight = std::max(this->jumpData.curHeight, 0.0f);
    this->point->y = this->jumpData.point.y - this->jumpData.curHeight;
    if (this->jumpData.curHeight <= 0)
    {
        this->jumpData.point = Vector2{this->point->x, this->point->y};
        this->status = this->status ^ NinjaCharacterStatus::FALL | NinjaCharacterStatus::IDLE;
    }
}
#include "animation.h"
#include "raylib.h"
#include <iostream>

Animation::Animation(char *filePath, Vector2 *point, float frameWidth, float frameHeight, int frameSize,
                     float frameTimeLimit)
{
    this->curFrameNum = 0;
    this->frameTimeBuffer = 0;
    this->frameTimeLimit = frameTimeLimit;
    this->frameSize = frameSize;

    this->texture = LoadTexture(filePath);
    this->frameWidth = frameWidth;
    this->frameHeight = frameHeight;
    this->point = point;
    this->frameRectangle = new Rectangle{0, 0, this->frameWidth, this->frameHeight};
}

Animation::~Animation()
{
    UnloadTexture(this->texture);
}

void Animation::Play()
{
    this->Play(AnimationDirection::RIGHT);
}

void Animation::Play(AnimationDirection direction)
{
    if (direction == AnimationDirection::UP)
    {
        this->frameRectangle->width = this->frameWidth;
        this->frameRectangle->height = this->frameHeight;
    }
    if (direction == AnimationDirection::DOWN)
    {
        this->frameRectangle->width = this->frameWidth;
        this->frameRectangle->height = -this->frameHeight;
    }
    if (direction == AnimationDirection::LEFT)
    {
        this->frameRectangle->width = -this->frameWidth;
        this->frameRectangle->height = this->frameHeight;
    }
    if (direction == AnimationDirection::RIGHT)
    {
        this->frameRectangle->width = this->frameWidth;
        this->frameRectangle->height = this->frameHeight;
    }

    float lastFrameTime = GetFrameTime();
    this->frameTimeBuffer += lastFrameTime;
    if (this->frameTimeBuffer > this->frameTimeLimit)
    {
        this->curFrameNum++;
        if (this->curFrameNum > this->frameSize)
        {
            this->frameRectangle->x = 0;
            this->curFrameNum = 0;
        }
        else
        {
            this->frameRectangle->x += this->frameWidth;
        }
        this->frameTimeBuffer -= this->frameTimeLimit;
    }
    DrawTextureRec(this->texture, *this->frameRectangle, *this->point, WHITE);
}
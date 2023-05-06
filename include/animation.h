#ifndef ANIMATION_H_
#define ANIMATION_H_
#include "raylib.h"
class Animation
{
  public:
    Animation(char *filePath, Vector2 *point, float frameWidth, float frameHeight, int frameSize, float frameTimeLimit);
    Animation(Animation &&) = default;
    Animation(const Animation &) = default;
    Animation &operator=(Animation &&) = default;
    Animation &operator=(const Animation &) = default;
    ~Animation();

    void Play();

  private:
    Texture2D texture;
    Vector2 *point;
    // 动画时间缓冲
    float frameTimeBuffer;
    float frameTimeLimit;
    int curFrameNum;
    // 动画帧大小
    int frameSize;
    float frameWidth;
    float frameHeight;
    Rectangle *frameRectangle;
    char *animationFile;
};

#endif // !ANIMATION_H_
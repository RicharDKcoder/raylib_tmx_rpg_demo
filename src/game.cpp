#include "game.h"
#include "character.h"
#include "map_system.h"
#include "ninja_character.h"
#include "raylib.h"

Game::Game()
{
    const int screenWidth = 960;
    const int screenHeight = 640;
    InitWindow(screenWidth, screenHeight, "basic window");

    SetTargetFPS(60);
    MapSystem *mapSystem = new MapSystem();
    this->mapSystem = mapSystem;

    Character *character = new NinjaCharacter();
    this->character = character;
}

Game::~Game()
{
    delete this->mapSystem;
}

void Game::HandlerEvent()
{
    this->character->HandlerEvent();
}

void Game::Draw()
{
    // 画地图
    this->mapSystem->Draw();
    // 画人物
    this->character->Draw();
}

void Game::Run()
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // 处理事件
        this->HandlerEvent();
        // 绘图
        this->Draw();
        EndDrawing();
    }
    CloseWindow();
}

void Game::Pause()
{
}
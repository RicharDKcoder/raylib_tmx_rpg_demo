#include "game.h"
#include "ninja_character.h"
#include "raylib.h"

Game::Game(GameConfig config)
{
    this->config = config;
    InitWindow(config.GetScreenWidth(), config.GetScreenHeight(), config.GetTitle());

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

void Game::Update()
{
    this->character->Update();
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
        // 更新
        this->Update();
        // 处理事件
        this->HandlerEvent();
        // 绘图
        this->Draw();
        DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
}

void Game::Pause()
{
}
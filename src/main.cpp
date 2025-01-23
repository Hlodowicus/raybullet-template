#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "include/player.hpp"
#include "include/world.hpp"
#include "include/geometry3.hpp"

int main(void) {
    InitWindow(0, 0, "ray");
    SetTargetFPS(60);
    ToggleFullscreen();
    DisableCursor();

    World* world = new World(0.0f, -9.81f, 0.0f);

    Ground* ground = new Ground();
    world->AddBody(ground->rigidBody);

    Player* player = new Player();

    Cube* cube = new Cube(Vector3{0.0f, 20.0f, 0.0f});
    world->AddBody(cube->rigidBody);

    Cube* cube2 = new Cube(Vector3{0.5f, 0.0f, 0.0f});
    world->AddBody(cube2->rigidBody);

    int num = 1500;
    Cube* cubes[num];

    for (int i = 0; i < num; i++)
    {
        cubes[i] = new Cube(Vector3{
            (float)GetRandomValue(-1, 1),
            (float)i * 3.0f,
            (float)GetRandomValue(-1, 1)
        });
        world->AddBody(cubes[i]->rigidBody);
    }
    

    while(!WindowShouldClose()) {
        //UPDATE
        player->Update();
        
        for (int i = 0; i < 50; i++)
        {
            world->dynamicsWorld->stepSimulation(GetFrameTime() / 60.f, 10);
        }
        

        
        

        //DRAW
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(player->cam);

        DrawGrid(20, 5);
        cube->Draw();
        cube2->Draw();
        for (int i = 0; i < num; i++)
        {
            cubes[i]->Draw();
        }
        

        EndMode3D();

        DrawFPS(10, 10);

        EndDrawing();
    }

    for (int i = 0; i < num; i++)
    {
        world->RemoveBody(cubes[i]->rigidBody);
        delete cubes[i];
    }

    world->RemoveBody(cube2->rigidBody);
    delete cube2;
    world->RemoveBody(cube->rigidBody);
    delete cube;
    world->RemoveBody(ground->rigidBody);
    delete ground;
    delete player;
    delete world;

    CloseWindow();

    return 0;
}
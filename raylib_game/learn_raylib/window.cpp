#include <iostream>
#include "raylib.h"


// c / c++ edit configure json
//  tasks configure default build task


int main(){

    const   int screenWidth = 800;
    const   int screenHeight = 600;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "basic window use raylib");
    SetTargetFPS(120);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(IsKeyPressed(KEY_A)){
            ToggleFullscreen();
        }
        DrawFPS(10,10);
        DrawText(TextFormat("Screen Size: [%i, %i]", GetScreenWidth(), GetScreenHeight()), 10, 40, 10, GREEN);
        DrawText("hello you has succeeded your first window", 200, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}



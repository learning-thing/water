#include <iostream>
#include <raylib.h>
#include "water.hpp"
#include "rlights.hpp"

int main() {
    std::cout << "Hello world!\n";

    InitWindow(1080, 720, "water shader stuff idk");
    SetTargetFPS(100);
    Water water;
    
    Camera3D camera;
    camera.position = (Vector3){10, 5, 10};
    camera.target = (Vector3){0, 0, 0};
    camera.fovy = 60.0f;
    camera.up = (Vector3){0, 1, 0};
    camera.projection = CAMERA_PERSPECTIVE;
    
    bool rotate = false;

    while (!WindowShouldClose()) {
        water.update(GetFrameTime());
        if (rotate)  {
            UpdateCamera(&camera, CAMERA_ORBITAL);
        }
        if (IsKeyPressed(KEY_SPACE)) rotate = !rotate;

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode3D(camera);
                //Light lights[MAX_LIGHTS] = { 0 };
                
                water.Draw();
            EndMode3D();
            DrawFPS(10, 10);
        EndDrawing();
    }
    
    return 0;
}

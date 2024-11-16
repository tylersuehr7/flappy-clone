#include "game_runner.hpp"
#include "sounds.hpp"
#include <raylib.h>

constexpr const int windowWidth = 600;
constexpr const int windowHeight = 520;
constexpr const int fps = 60;

void GameRunner::run(const int argc, const char **argv) {
    InitWindow(windowWidth, windowHeight, "Flappy");
    InitAudioDevice();
    SetTargetFPS(fps);

    Sounds::load_sounds();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    Sounds::unload_sounds();

    CloseAudioDevice();
    CloseWindow();
}

#pragma once

#include <raylib.h>

typedef struct {
    const Vector2 size;
    const Color background_color;
    const float gravity;
} World;

class Game {
private:
    bool m_game_over;
    bool m_started;
    int m_score;
    World m_world;
public:
    Game(const World world);
    void on_update(void);
    void on_render(void);
};

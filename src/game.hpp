#pragma once

#include "player.hpp"
#include "world.hpp"
#include <raylib.h>

class Game {
private:
    bool m_game_over;
    bool m_started;
    int m_score;
    World m_world;
    Player m_player;
public:
    Game(const World world);
    void on_update(void);
    void on_render(void);
};

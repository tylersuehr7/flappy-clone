#pragma once

#include "player.hpp"
#include "pipe.hpp"
#include "world.hpp"
#include <raylib.h>
#include <vector>

class Game {
private:
    bool m_game_over;
    bool m_started;
    int m_game_speed;
    int m_score;
    World m_world;
    Player m_player;
    std::vector<Pipe> m_pipes;
public:
    Game(const World world);
    void on_update(void);
    void on_render(void);
private:
    void setup_pipes(void);
};

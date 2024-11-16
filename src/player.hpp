#pragma once

#include "game.hpp"
#include <raylib.h>

class Player {
private:
    const World &m_world;
    Rectangle m_bounds;
    float m_velocity;
public:
    Player(const World &world);
    Player(const World &world, const Rectangle bounds);
};

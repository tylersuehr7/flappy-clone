#pragma once

#include <raylib.h>

class Player {
private:
    Rectangle m_bounds;
    float m_velocity;
public:
    Player() = default;
    Player(const Rectangle bounds);
};

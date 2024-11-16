#pragma once

#include "world.hpp"
#include <raylib.h>

class Player {
private:
    const World &m_world;
    Color m_color;
    Rectangle m_bounds;
    float m_velocity;
public:
    Player(const World &world);
    Player(const World &world, const Rectangle bounds);
    void update(void);
    void draw(void);
    void reset(void);
    bool check_collision_with_ground(void);
};

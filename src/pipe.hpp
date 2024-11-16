#pragma once

#include "world.hpp"
#include <raylib.h>

class Pipe {
public:
    static float s_spacing;
    static Color s_color;
private:
    const World &m_world;
    Rectangle m_bounds;
    bool m_passed;
public:
    Pipe(const World &world, const float offset_x);
    Pipe(const World &world, const Rectangle bounds);
    void update(const float speed);
    void draw(void);
    bool is_passed_player(void);
};

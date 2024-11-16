#pragma once

#include "world.hpp"
#include <raylib.h>

class Pipe {
private:
    static Color s_color;
    const World &m_world;
    Rectangle m_bounds;
    float m_spacing;
    bool m_passed;
public:
    Pipe(const World &world, const float offset_x);
    Pipe(const World &world, const Rectangle bounds);
    void update(const float speed);
    void draw(void);
    static void set_color(const Color color);
};

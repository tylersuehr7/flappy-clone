#pragma once

#include "world.hpp"
#include <raylib.h>

class Pipe {
private:
    const World &m_world;
    Rectangle m_bounds;
    float m_spacing;
    bool m_passed;
public:
    Pipe(const World &world, const float offset_x);
    Pipe(const World &world, const Rectangle bounds);
};

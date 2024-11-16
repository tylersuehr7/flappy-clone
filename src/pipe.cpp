#include "pipe.hpp"

Pipe::Pipe(const World &world, const float offset_x): 
    m_world(world),
    m_passed(false), 
    m_spacing(100.0f), 
    m_bounds() {
    m_bounds.x = m_world.size.x + offset_x;
    m_bounds.y = GetRandomValue(-50, 50);
}

Pipe::Pipe(const World &world, const Rectangle bounds):
    m_world(world),
    m_passed(false),
    m_spacing(100.0f),
    m_bounds(bounds) {
}

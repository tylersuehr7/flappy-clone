#include "pipe.hpp"

Color Pipe::s_color = BLACK;
float Pipe::s_spacing = 100.0f;

Pipe::Pipe(const World &world, const float offset_x): 
    m_world(world),
    m_passed(false),
    m_bounds((Rectangle) {.width=20}) {
    m_bounds.height = (m_world.size.y / 2.0f) - (Pipe::s_spacing / 2.0f);
    m_bounds.x = m_world.size.x + offset_x;
    m_bounds.y = GetRandomValue(-50, 50);
}

Pipe::Pipe(const World &world, const Rectangle bounds):
    m_world(world),
    m_passed(false),
    m_bounds(bounds) {
}

void Pipe::update(const float speed) {
    m_bounds.x -= speed * GetFrameTime();
    if (m_bounds.x < -100) {
        m_bounds.x = m_world.size.x;
        m_bounds.y = GetRandomValue(-50, 50);
        m_passed = false;
    }
}

void Pipe::draw() {
    // 1 pipe = 2 split pipes (top and bottom) with gap in between
    DrawRectangle(
        m_bounds.x,
        0,
        m_bounds.width,
        m_bounds.height - m_bounds.y,
        Pipe::s_color
    );
    DrawRectangle(
        m_bounds.x,
        -m_bounds.y + m_world.size.y - m_bounds.height,
        m_bounds.width,
        m_bounds.height + m_bounds.y,
        Pipe::s_color
    );
}

#include "player.hpp"
#include "sounds.hpp"
#include <cmath>

Player::Player(const World &world): 
    m_world(world), 
    m_bounds((Rectangle) {.height=10, .width=10}), 
    m_velocity(0.0f),
    m_color(BLACK) {
    reset();
}

Player::Player(const World &world, const Rectangle bounds):
    m_world(world),
    m_bounds(bounds),
    m_velocity(0.0f),
    m_color(BLACK) {
}

void Player::update() {
    if (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        // The jumping movement
        m_velocity = sqrt(-2 * m_world.gravity * 0.5f);
        Sounds::play_jump();
    } else {
        m_velocity += m_world.gravity * GetFrameTime();
    }
    m_bounds.y -= m_velocity;
}

void Player::draw() {
    DrawRectangleRec(m_bounds, m_color);
}

void Player::reset() {
    m_bounds.x = (m_world.size.x / 2) - m_bounds.width;
    m_bounds.y = (m_world.size.y / 2) - m_bounds.height;
    m_velocity = 0.0f;
}

bool Player::check_collision_with_ground() {
    return m_bounds.y > m_world.size.y - m_bounds.height;
}

const Rectangle& Player::get_bounds() {
    return m_bounds;
}

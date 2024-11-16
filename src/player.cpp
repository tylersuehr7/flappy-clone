#include "player.hpp"

Player::Player(const World &world): 
    m_world(world), 
    m_bounds((Rectangle) {.height=10, .width=10}), 
    m_velocity(0.0f) {
    m_bounds.x = (world.size.x / 2) - m_bounds.width;
    m_bounds.y = (world.size.y / 2) - m_bounds.height;
}

Player::Player(const World &world, const Rectangle bounds):
    m_world(world),
    m_bounds(bounds),
    m_velocity(0.0f) {
}

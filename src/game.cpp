#include "game.hpp"

Game::Game(const World world): m_score(0), m_game_over(false), m_started(false), m_world(world) {
}

void Game::on_update() {
    // TODO: update game logic here…
}

void Game::on_render() {
    ClearBackground(m_world.background_color);
    // TODO: draw game components here…
}

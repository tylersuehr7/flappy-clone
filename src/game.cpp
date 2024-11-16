#include "game.hpp"

Game::Game(const World world): 
    m_score(0), 
    m_game_over(false), 
    m_started(false), 
    m_world(world),
    m_player(m_world) {
}

void Game::on_update() {
    m_player.update();
}

void Game::on_render() {
    ClearBackground(m_world.background_color);
    m_player.draw();
}

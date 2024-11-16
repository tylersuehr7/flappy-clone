#include "game.hpp"

Game::Game(const World world): 
    m_score(0), 
    m_game_speed(100),
    m_game_over(false), 
    m_started(false), 
    m_world(world),
    m_player(m_world),
    m_pipes(std::vector<Pipe>()) {
    setup_pipes();
}

void Game::on_update() {
    m_player.update();
    for (auto &pipe : m_pipes) {
        pipe.update(m_game_speed);
    }
}

void Game::on_render() {
    ClearBackground(m_world.background_color);
    m_player.draw();
    for (auto &pipe : m_pipes) {
        pipe.draw();
    }
}

void Game::setup_pipes() {
    const size_t num_pipes = (m_world.size.x + 100) / Pipe::s_spacing;
    for (size_t i = 0; i < num_pipes; i++) {
        Pipe pipe(m_world, i * Pipe::s_spacing);
        m_pipes.push_back(pipe);
    }
}

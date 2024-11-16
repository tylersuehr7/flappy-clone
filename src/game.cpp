#include "game.hpp"
#include "sounds.hpp"

static Font s_font;
static float s_text_spacing;
static struct {
    Vector2 size; 
    Vector2 offset;
} s_text_buffers;

Game::Game(const World world): 
    m_score(0), 
    m_game_speed(100),
    m_game_over(false), 
    m_started(false), 
    m_world(world),
    m_player(m_world),
    m_pipes(std::vector<Pipe>()) {
    s_font = GetFontDefault();
    s_text_spacing = 4.0f;
    reset_game_objects();
}

void Game::on_update() {
    if (!m_started && (IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
        m_started = true;
    }

    if (!m_game_over && m_started) {
        m_player.update();

        for (auto &pipe : m_pipes) {
            pipe.update(m_game_speed);

            if (pipe.is_passed_player()) {
                increment_score(1);
            }

            if (pipe.check_collion_with_player(m_player.get_bounds())) {
                Sounds::play_die();
                m_game_over = true;
            }
        }

        if (!m_game_over && m_player.check_collision_with_ground()) {
            Sounds::play_die();
            m_game_over = true;
        }
    }

    if (m_game_over && (IsKeyPressed(KEY_ENTER))) {
        reset_game_objects();
        m_game_over = false;
        m_score = 0;
    }
}

void Game::on_render() {
    ClearBackground(m_world.background_color);

    if (m_started) {
        m_player.draw();
        for (auto &pipe : m_pipes) {
            pipe.draw();
        }
    }

    if (m_game_over) {
        s_text_buffers.size = MeasureTextEx(s_font, "GAME OVER", 30, s_text_spacing);
        s_text_buffers.offset.x = (m_world.size.x / 2.0f) - (s_text_buffers.size.x / 2.0f);
        s_text_buffers.offset.y = (m_world.size.y / 2.0f) - (s_text_buffers.size.y / 2.0f);
        DrawTextEx(s_font, "GAME OVER", s_text_buffers.offset, 30, s_text_spacing, RED);

        s_text_buffers.offset.y += s_text_buffers.size.y;
        s_text_buffers.size = MeasureTextEx(s_font, "Press ENTER to RESTART", 10, s_text_spacing);
        s_text_buffers.offset.x = (m_world.size.x / 2.0f) - (s_text_buffers.size.x / 2.0f);
        DrawTextEx(s_font, "Press ENTER to RESTART", s_text_buffers.offset, 10, s_text_spacing, RED);
    }

    if (!m_started) {
        s_text_buffers.size = MeasureTextEx(s_font, "Press SPACE to JUMP", 30, s_text_spacing);
        s_text_buffers.offset.x = (m_world.size.x / 2.0f) - (s_text_buffers.size.x / 2.0f);
        s_text_buffers.offset.y = (m_world.size.y / 2.0f) - (s_text_buffers.size.y / 2.0f);
        DrawTextEx(s_font, "Press SPACE to JUMP", s_text_buffers.offset, 30, s_text_spacing, LIGHTGRAY);
    }

    s_text_buffers.offset.x = 10.0f;
    s_text_buffers.offset.y = 10.0f;
    DrawTextEx(s_font, TextFormat("SCORE: %d", m_score), s_text_buffers.offset, 14, s_text_spacing, LIGHTGRAY);
}

void Game::reset_game_objects() {
    m_player.reset();
    m_pipes.clear();
    const size_t num_pipes = (m_world.size.x + 100) / Pipe::s_spacing;
    for (size_t i = 0; i < num_pipes; i++) {
        Pipe pipe(m_world, i * Pipe::s_spacing);
        m_pipes.push_back(pipe);
    }
}

void Game::increment_score(const int points) {
    m_score += points;
    if (m_score % 10 == 0) {
        Sounds::play_level_up();
    } else {
        Sounds::play_score();
    }
}

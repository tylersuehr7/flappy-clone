#pragma once

#include <raylib.h>

class Game {
private:
    bool m_game_over;
    bool m_started;
    int m_score;
public:
    Game();
    void on_update(void);
    void on_render(void);
};

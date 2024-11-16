#include "sounds.hpp"
#include <raylib.h>

Sound g_level_up_sound;
Sound g_score_sound;
Sound g_jump_sound;
Sound g_die_sound;

void Sounds::load_sounds() {
    g_level_up_sound = LoadSound("LevelUp.wav");
    g_score_sound = LoadSound("Score.wav");
    g_jump_sound = LoadSound("Jump.wav");
    g_die_sound = LoadSound("Die.wav");
}

void Sounds::unload_sounds() {
    UnloadSound(g_level_up_sound);
    UnloadSound(g_score_sound);
    UnloadSound(g_jump_sound);
    UnloadSound(g_die_sound);
}

void Sounds::play_level_up() {
    PlaySound(g_level_up_sound);
}

void Sounds::play_score() {
    PlaySound(g_score_sound);
}

void Sounds::play_jump() {
    PlaySound(g_jump_sound);
}

void Sounds::play_die() {
    PlaySound(g_die_sound);
}

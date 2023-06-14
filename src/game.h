//
// Created by james on 14/06/2023.
//

#ifndef SDL_GAMING_GAME_H
#define SDL_GAMING_GAME_H

#include "paddle.h"
#include "ball.h"
#include "sdl_data.h"

typedef struct {
    paddle* left_paddle;
    paddle* right_paddle;

    int left_score;
    int right_score;

    int win_threshold;

    ball* ball;
} game;

void game_events(game* game, SDL_Event* event);
void game_physics(game* game, sdl_data* sdl_data);
void game_render(game* game, sdl_data* sdl_data);
game* game_initialize(sdl_data* sdl_data);
void game_free(game* game);


#endif //SDL_GAMING_GAME_H

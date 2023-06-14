//
// Created by james on 13/06/2023.
//

#ifndef SDL_GAMING_BALL_H
#define SDL_GAMING_BALL_H

#include "SDL.h"
#include "paddle.h"

typedef enum {
    LEFT,
    RIGHT,
    NONE
} ball_score;

typedef struct {
    float x, y;
    float vx, vy;
    float radius;
    Uint8 r, g, b, a;
    Uint64 last_physics_update;
} ball;

ball_score ball_physics(ball* ball, int window_width, int window_height, paddle** paddles, int num_paddles);
void ball_render(ball* ball, SDL_Renderer* renderer);
ball* ball_initialize(float x, float y, float radius,
                      Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void ball_free(ball* ball);

#endif //SDL_GAMING_BALL_H

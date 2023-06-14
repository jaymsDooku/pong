//
// Created by james on 13/06/2023.
//

#ifndef SDL_GAMING_PADDLE_H
#define SDL_GAMING_PADDLE_H

#include <SDL.h>
#include <stdbool.h>

typedef struct {
    float x, y;
    float vx, vy;
    float w, h;
    Uint8 r, g, b, a;
    Uint64 last_physics_update;
} paddle;

bool paddle_is_inside(paddle* paddle, float x, float y);
void paddle_physics(paddle* paddle, int window_width, int window_height);
void paddle_render(paddle* paddle, SDL_Renderer* renderer);
paddle* paddle_initialize(float x, float y, float w, float h,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void paddle_free(paddle* paddle);

#endif //SDL_GAMING_PADDLE_H

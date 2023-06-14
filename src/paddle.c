//
// Created by james on 13/06/2023.
//

#include "paddle.h"

bool paddle_is_inside(paddle* paddle, float x, float y) {
    return x > paddle->x && x < paddle->x + paddle->w &&
            y > paddle->y && y < paddle->y + paddle->h;
}

void paddle_physics(paddle* paddle, int window_width, int window_height) {
    Uint64 current_ticks = SDL_GetTicks();
    float dt = (current_ticks - paddle->last_physics_update) / 1000.f;

    paddle->x += paddle->vx * dt;
    paddle->y += paddle->vy * dt;

    if (paddle->y < 0) {
        paddle->y = 0;
        paddle->vy = -paddle->vy;
    }
    if (paddle->y + paddle->h > window_height) {
        paddle->y = window_height - paddle->h;
        paddle->vy = -paddle->vy;
    }

    if (paddle->vx > 0) {
        paddle->vx -= 0.2f;
    }
    if (paddle->vy > 0) {
        paddle->vy -= 0.2f;
    }

    paddle->last_physics_update = current_ticks;
}

void paddle_render(paddle* paddle, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, paddle->r, paddle->g, paddle->b, paddle->a);
    SDL_FRect rect = { paddle->x, paddle->y, paddle->w, paddle->h };
    SDL_RenderRect(renderer, &rect);
}

paddle* paddle_initialize(float x, float y, float w, float h,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    paddle* result = malloc(sizeof(paddle));
    result->x = x;
    result->y = y;
    result->vx = 0;
    result->vy = 0;
    result->w = w;
    result->h = h;
    result->r = r;
    result->g = g;
    result->b = b;
    result->a = a;
    result->last_physics_update = SDL_GetTicks();
    return result;
}

void paddle_free(paddle* paddle) {
    free(paddle);
}
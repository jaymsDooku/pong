//
// Created by james on 13/06/2023.
//
#include "ball.h"

ball_score ball_physics(ball* ball, int window_width, int window_height, paddle** paddles, int num_paddles) {
    Uint64 current_ticks = SDL_GetTicks();

    float dt = (current_ticks - ball->last_physics_update) / 1000.f;

    ball->x += ball->vx * dt;
    ball->y += ball->vy * dt;

    if (ball->y < 0) {
        ball->y = 0;
        ball->vy = -ball->vy;
    }
    if (ball->y + ball->radius > window_height) {
        ball->y = window_height - ball->radius;
        ball->vy = -ball->vy;
    }
    if (ball->x < 0) {
        ball->x = 0;
        ball->vx = -ball->vx;
        return LEFT;
    }
    if (ball->x + ball->radius > window_width) {
        ball->x = window_width - ball->radius;
        ball->vx = -ball->vx;
        return RIGHT;
    }

    float up = ball->y - ball->radius;
    float down = ball->y + ball->radius;
    float left = ball->x - ball->radius;
    float right = ball->x + ball->radius;
    for (int i = 0; i < num_paddles; i++) {
        paddle* paddle = paddles[i];
        if (paddle_is_inside(paddle, right, ball->y) || paddle_is_inside(paddle, left, ball->y)) {
            ball->vx = -ball->vx;
        }
        if (paddle_is_inside(paddle, ball->x, up) || paddle_is_inside(paddle, ball->x, down)) {
            ball->vy = -ball->vy;
        }
    }

    ball->last_physics_update = current_ticks;
    return NONE;
}

void ball_render(ball* ball, SDL_Renderer* renderer) {
    int x0 = ball->x;
    int y0 = ball->y;
    int radius = ball->radius;
    int x = radius - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radius << 1);

    SDL_SetRenderDrawColor(renderer, ball->r, ball->g, ball->b, ball->a);
    while (x >= y) {
        SDL_RenderPoint(renderer, x0 + x, y0 + y);
        SDL_RenderPoint(renderer, x0 + y, y0 + x);
        SDL_RenderPoint(renderer, x0 - y, y0 + x);
        SDL_RenderPoint(renderer, x0 - x, y0 + y);
        SDL_RenderPoint(renderer, x0 - x, y0 - y);
        SDL_RenderPoint(renderer, x0 - y, y0 - x);
        SDL_RenderPoint(renderer, x0 + y, y0 - x);
        SDL_RenderPoint(renderer, x0 + x, y0 - y);

        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius << 1);
        }
    }
}

ball* ball_initialize(float x, float y, float radius,
                      Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    ball* result = malloc(sizeof(ball));
    result->x = x;
    result->y = y;
    result->vx = 0;
    result->vy = 0;
    result->radius = radius;
    result->r = r;
    result->g = g;
    result->b = b;
    result->a = a;
    result->last_physics_update = SDL_GetTicks();
    return result;
}

void ball_free(ball* ball) {
    free(ball);
}
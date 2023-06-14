//
// Created by james on 14/06/2023.
//

#include "game.h"
#include "text.h"
#include <stdio.h>

void game_events(game* game, SDL_Event* event) {
    if (event->type == SDL_EVENT_KEY_DOWN) {
        if (event->key.keysym.sym == SDLK_UP) {
            game->left_paddle->vy += -3;
            game->right_paddle->vy += -3;
        } else if (event->key.keysym.sym == SDLK_DOWN) {
            game->left_paddle->vy += 3;
            game->right_paddle->vy += 3;
        } else if (event->key.keysym.sym == SDLK_SPACE) {
            game->ball->vx = 100;
            game->ball->vy = 100;
        }
    }
}

void game_physics(game* game, sdl_data* sdl_data) {
    paddle_physics(game->left_paddle, sdl_data->window_surface->w, sdl_data->window_surface->h);
    paddle_physics(game->right_paddle, sdl_data->window_surface->w, sdl_data->window_surface->h);
    paddle* paddles[2] = { game->left_paddle, game->right_paddle };
    ball_score ball_score = ball_physics(game->ball, sdl_data->window_surface->w, sdl_data->window_surface->h, paddles, 2);
    if (ball_score == LEFT) {
        game->left_score++;
    } else if (ball_score == RIGHT) {
        game->right_score++;
    }
}

SDL_Color textColor = { 255, 255, 255 };

void game_render(game* game, sdl_data* sdl_data) {
    paddle_render(game->left_paddle, sdl_data->renderer);
    paddle_render(game->right_paddle, sdl_data->renderer);
    ball_render(game->ball, sdl_data->renderer);

    char left_score_str[100];
    snprintf(left_score_str, sizeof(left_score_str), "%d", game->left_score);
    text_render(sdl_data, left_score_str, textColor, 5, 5);

    char right_score_str[100];
    snprintf(right_score_str, sizeof(right_score_str), "%d", game->right_score);
    text_render(sdl_data, right_score_str, textColor, sdl_data->window_surface->w - 10, 5);
}

game* game_initialize(sdl_data* sdl_data) {
    game* result = malloc(sizeof(game));
    SDL_Surface* window_surface = sdl_data->window_surface;
    paddle* left_paddle = paddle_initialize(10, 40, 20, 100,
                                        0xFF, 0xFF, 0xFF, 0xFF);
    paddle* right_paddle = paddle_initialize(window_surface->w - 30, 40, 20, 100,
                                        0xFF, 0xFF, 0xFF, 0xFF);
    ball* ball = ball_initialize((window_surface->w / 2), (window_surface->h / 2), 10, 0xFF, 0xFF, 0xFF, 0xFF);
    result->left_paddle = left_paddle;
    result->right_paddle = right_paddle;
    result->ball = ball;

    result->left_score = 0;
    result->right_score = 0;
    result->win_threshold = 10;

    return result;
}

void game_free(game* game) {
    paddle_free(game->left_paddle);
    paddle_free(game->right_paddle);
    ball_free(game->ball);
    free(game);
}

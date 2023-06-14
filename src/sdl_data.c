//
// Created by james on 14/06/2023.
//

#include "sdl_data.h"

sdl_data* sdl_data_initialize() {
    if (SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
        return NULL;
    }

    SDL_Window* window = SDL_CreateWindow("Pong!", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
    if (!window) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
        return NULL;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
        return NULL;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    if (TTF_Init() == -1) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, TTF_GetError());
        return NULL;
    }

    TTF_Font* font = TTF_OpenFont("fonts/OpenSans-Regular.ttf", 16);
    if (!font) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, TTF_GetError());
        return NULL;
    }

    SDL_Surface* window_surface = SDL_GetWindowSurface(window);

    sdl_data* result = malloc(sizeof(sdl_data));
    result->window = window;
    result->window_surface = window_surface;
    result->renderer = renderer;
    result->font = font;
    return result;
}

void sdl_data_free(sdl_data* sdl_data) {
    SDL_DestroySurface(sdl_data->window_surface);
    SDL_DestroyRenderer(sdl_data->renderer);
    SDL_DestroyWindow(sdl_data->window);

    TTF_CloseFont(sdl_data->font);

    TTF_Quit();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

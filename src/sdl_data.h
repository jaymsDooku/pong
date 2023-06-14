//
// Created by james on 14/06/2023.
//

#ifndef SDL_GAMING_SDL_DATA_H
#define SDL_GAMING_SDL_DATA_H

#include "SDL.h"
#include "SDL_ttf.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct {
    SDL_Window* window;
    SDL_Surface* window_surface;
    SDL_Renderer* renderer;
    TTF_Font* font;
} sdl_data;

sdl_data* sdl_data_initialize();
void sdl_data_free(sdl_data* sdl_data);

#endif //SDL_GAMING_SDL_DATA_H

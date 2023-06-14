//
// Created by james on 12/06/2023.
//

#ifndef SDL_GAMING_TEXTURE_H
#define SDL_GAMING_TEXTURE_H

#include "SDL.h"

typedef struct {
    int w;
    int h;
    SDL_Texture* handle;
} texture;

void texture_render(texture* texture, SDL_Renderer* renderer, int x, int y);
texture* texture_initialize(SDL_Texture* handle, int w, int h);
void texture_free(texture* texture);

#endif //SDL_GAMING_TEXTURE_H

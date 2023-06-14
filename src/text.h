//
// Created by james on 12/06/2023.
//

#ifndef SDL_GAMING_TEXT_H
#define SDL_GAMING_TEXT_H

#include "sdl_data.h"
#include "texture.h"

texture* text_texture(sdl_data* sdl_data, const char* text, SDL_Color color);
void text_render(sdl_data* sdl_data, const char* text, SDL_Color color, int x, int y);

#endif //SDL_GAMING_TEXT_H

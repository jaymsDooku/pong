//
// Created by james on 14/06/2023.
//

#ifndef SDL_GAMING_BUTTON_H
#define SDL_GAMING_BUTTON_H

#include "sdl_data.h"
#include "texture.h"

#include <stdbool.h>

typedef struct {
    float x, y;
    float w, h;
    Uint8 r, g, b, a;
    texture* text_texture;
    void (*on_click)();
} button;

bool button_is_inside(button* button, float x, float y);
void button_render(button* button, SDL_Renderer* renderer);
button* button_initialize(float x, float y, float w, float h,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a,
                          sdl_data* sdl_data, char* text,
                          Uint8 tr, Uint8 tg, Uint8 tb, Uint8 ta,
                          void (*on_click)());
void button_free(button* button);

#endif //SDL_GAMING_BUTTON_H

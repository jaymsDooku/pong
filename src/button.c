//
// Created by james on 14/06/2023.
//

#include "button.h"
#include "text.h"

#include <stdlib.h>

bool button_is_inside(button* button, float x, float y) {
    return x > button->x && x < button->x + button->w &&
           y > button->y && y < button->y + button->h;
}

void button_render(button* button, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, button->r, button->g, button->b, button->a);
    SDL_FRect rect = { button->x, button->y, button->w, button->h };
    SDL_RenderFillRect(renderer, &rect);

    float cx = button->x + (button->w / 2);
    float cy = button->y + (button->h / 2);
    texture_render(button->text_texture, renderer, cx - (button->text_texture->w / 2), cy - (button->text_texture->h / 2));
}

button* button_initialize(float x, float y, float w, float h,
                          Uint8 r, Uint8 g, Uint8 b, Uint8 a,
                          sdl_data* sdl_data, char* text,
                          Uint8 tr, Uint8 tg, Uint8 tb, Uint8 ta,
                          void (*on_click)()) {
    button* result = malloc(sizeof(button));
    result->x = x;
    result->y = y;
    result->w = w;
    result->h = h;
    result->r = r;
    result->g = g;
    result->b = b;
    result->a = a;

    SDL_Color text_color = {tr,tg,tb,ta};
    texture* texture = text_texture(sdl_data, text, text_color);

    result->text_texture = texture;
    result->on_click = on_click;
    return result;
}

void button_free(button* button) {
    texture_free(button->text_texture);
    free(button);
}

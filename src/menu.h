//
// Created by james on 14/06/2023.
//

#ifndef SDL_GAMING_MENU_H
#define SDL_GAMING_MENU_H

#include "app_state.h"
#include "sdl_data.h"
#include "button.h"

typedef struct {
    button* play_button;
    button* quit_button;
} menu;

void menu_events(menu* menu, SDL_Event* event, app_state* app_state);
void menu_render(menu* menu, sdl_data* sdl_data);
menu* menu_initialize(sdl_data* sdl_data, void (*play_click)(), void (*quit_click)());
void menu_free(menu* menu);

#endif //SDL_GAMING_MENU_H

//
// Created by james on 14/06/2023.
//

#include "menu.h"

#include <stdio.h>

void menu_events(menu* menu, SDL_Event* event, app_state* app_state) {
    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        float button_x = event->button.x;
        float button_y = event->button.y;
        if (button_is_inside(menu->play_button, button_x, button_y)) {
            menu->play_button->on_click(app_state);
        }
        if (button_is_inside(menu->quit_button, button_x, button_y)) {
            menu->quit_button->on_click(app_state);
        }
    }
}

void menu_render(menu* menu, sdl_data* sdl_data) {
    button_render(menu->play_button, sdl_data->renderer);
    button_render(menu->quit_button, sdl_data->renderer);
}

menu* menu_initialize(sdl_data* sdl_data, void (*play_click)(), void (*quit_click)()) {
    menu* result = malloc(sizeof(menu));

    SDL_Surface* window_surface = sdl_data->window_surface;
    button* play_button = button_initialize((window_surface->w / 2) - 50, (window_surface->h / 2) - 50, 100, 50,
                                            0xFF, 0xFF, 0xFF, 0xAA,
                                            sdl_data, "Play",
                                            0xFF, 0x00, 0x00, 0xFF,
                                            play_click);
    result->play_button = play_button;
    button* quit_button = button_initialize((window_surface->w / 2) - 50, (window_surface->h / 2) + 50, 100, 50,
                                            0xFF, 0xFF, 0xFF, 0xAA,
                                            sdl_data, "Quit",
                                            0xFF, 0x00, 0x00, 0xFF,
                                            quit_click);
    result->quit_button = quit_button;

    return result;
}

void menu_free(menu* menu) {
    button_free(menu->play_button);
    button_free(menu->quit_button);
    free(menu);
}
//
// Created by james on 14/06/2023.
//

#ifndef SDL_GAMING_APP_H
#define SDL_GAMING_APP_H

#include "SDL.h"
#include "button.h"
#include "game.h"
#include "menu.h"
#include "app_state.h"

#include <stdbool.h>

#define FPS 300

typedef struct {
    app_state* app_state;
    sdl_data* sdl_data;

    float ticks_per_frame;

    menu* menu;
    game* game;
} app;

void app_events(app* app);
void app_physics(app* app);
void app_render(app* app);
void app_run(app* app);
app* app_initialize();
void app_free(app* app);

#endif //SDL_GAMING_APP_H

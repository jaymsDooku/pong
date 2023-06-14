//
// Created by james on 14/06/2023.
//

#ifndef SDL_GAMING_APP_STATE_H
#define SDL_GAMING_APP_STATE_H

#include "SDL.h"

#include <stdbool.h>

typedef enum {
    MENU,
    PLAY
} app_mode;

typedef struct {
    app_mode app_mode;

    bool is_running;
    SDL_Event event;
} app_state;

void play(app_state* app_state);
void quit(app_state* app_state);
app_state* app_data_initialize();
void app_data_free(app_state* app_state);

#endif //SDL_GAMING_APP_STATE_H

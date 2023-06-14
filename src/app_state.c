//
// Created by james on 14/06/2023.
//

#include "app_state.h"

#include <stdio.h>

void play(app_state* app_state) {
    printf("Play");
    app_state->app_mode = PLAY;
}

void quit(app_state* app_state) {
    printf("Quit");
    app_state->is_running = false;
}

app_state* app_data_initialize() {
    app_state* result = malloc(sizeof(app_state));
    result->app_mode = MENU;
    result->is_running = true;
    return result;
}

void app_data_free(app_state* app_state) {
    free(app_state);
}
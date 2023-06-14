//
// Created by james on 14/06/2023.
//

#include "app.h"
#include "text.h"

#include <stdio.h>
#include <stdlib.h>

void app_events(app* app) {
    SDL_Event* event = &app->app_state->event;
    while (SDL_PollEvent(event) != 0) {
        if (event->type == SDL_EVENT_QUIT) {
            quit(app->app_state);
        }
        if (app->app_state->app_mode == MENU) {
            menu_events(app->menu, event, app->app_state);
        } else {
            game_events(app->game, event);
        }
    }
}

void app_physics(app* app) {
    game_physics(app->game, app->sdl_data);
}

void app_render(app* app) {
    if (app->app_state->app_mode == MENU) {
        menu_render(app->menu, app->sdl_data);
    } else {
        game_render(app->game, app->sdl_data);
    }
}

void app_run(app* app) {
    SDL_Renderer* renderer = app->sdl_data->renderer;
    SDL_Color textColor = { 255, 255, 255 };
    while(app->app_state->is_running) {
        Uint64 startTicks = SDL_GetTicks();
        Uint64 startPerf = SDL_GetPerformanceCounter();

        app_events(app);
        app_physics(app);

        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        app_render(app);

        Uint64 endPerf = SDL_GetPerformanceCounter();

        float elapsedMS = (endPerf - startPerf) / ((float)SDL_GetPerformanceFrequency() * 1000.f);
        SDL_Delay(floor(app->ticks_per_frame - elapsedMS));

        Uint64 endTicks = SDL_GetTicks();
        float frameTime = (endTicks - startTicks) / 1000.f;

        char text[100];
        snprintf(text, sizeof(text), "%s%.01f", "Current FPS: ", (1.f / frameTime));
        text_render(app->sdl_data, text, textColor, 40, 10);

        SDL_RenderPresent(renderer);
    }
}

app* app_initialize() {
    sdl_data* sdl_data = sdl_data_initialize();
    if (!sdl_data) {
        return NULL;
    }

    app* app_instance = malloc(sizeof(app));
    app_state* app_state = app_data_initialize();
    app_instance->app_state = app_state;
    app_instance->sdl_data = sdl_data;
    app_instance->ticks_per_frame = 1000.f / FPS;

    menu* menu = menu_initialize(sdl_data, play, quit);
    app_instance->menu = menu;

    game* game = game_initialize(sdl_data);
    app_instance->game = game;

    return app_instance;
}

void app_free(app* app) {
    app_data_free(app->app_state);
    menu_free(app->menu);
    game_free(app->game);
    sdl_data_free(app->sdl_data);
    free(app);
}
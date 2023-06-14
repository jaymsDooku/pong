//
// Created by james on 13/06/2023.
//

#include "timer.h"

void start_timer(timer* timer) {
    if (timer->ticks > 0) {
        timer->ticks = SDL_GetTicks() - timer->ticks;
    } else {
        timer->ticks = SDL_GetTicks();
    }
    timer->running = true;
}

void stop_timer(timer* timer) {
    timer->ticks = SDL_GetTicks() - timer->ticks;
    timer->running = false;
}

void reset_timer(timer* timer) {
    timer->ticks = 0;
}

Uint64 get_time(timer* timer) {
    if (!timer->running) {
        return timer->ticks;
    }

    return SDL_GetTicks() - timer->ticks;
}

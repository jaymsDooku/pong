//
// Created by james on 13/06/2023.
//

#ifndef SDL_GAMING_TIMER_H
#define SDL_GAMING_TIMER_H

#include <SDL.h>
#include <stdbool.h>

typedef struct {
    Uint64 ticks;
    bool running;
} timer;

void start_timer(timer* timer);
void stop_timer(timer* timer);
void reset_timer(timer* timer);
Uint64 get_time(timer* timer);

#endif //SDL_GAMING_TIMER_H

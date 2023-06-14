#include <SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "app.h"

int main(int argc, char* argv[]) {
    app* app = app_initialize();
    if (!app) {
        return EXIT_FAILURE;
    }
    app_run(app);
    app_free(app);
    return 0;
}

//int main(int argc, char* argv[]) {
//    if (SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
//        rL_InitSubSystem(SDL_INIT_VIDEO)) {
//            SDeturn EXIT_FAILURE;
//    }
//
//    SDL_Window* window = SDL_CreateWindow("Pong!", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC);
//    if (!window) {
//        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
//        return EXIT_FAILURE;
//    }
//
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
//    if (!renderer) {
//        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
//        return EXIT_FAILURE;
//    }
//    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
//
//    if (TTF_Init() == -1) {
//        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, TTF_GetError());
//        return EXIT_FAILURE;
//    }
//
//    TTF_Font* font = TTF_OpenFont("fonts/TiltPrism.ttf", 16);
//    if (!font) {
//        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, TTF_GetError());
//        return EXIT_FAILURE;
//    }
//
//    SDL_Surface* window_surface = SDL_GetWindowSurface(window);
////    SDL_FillSurfaceRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
////    SDL_UpdateWindowSurface(window);
//
//    if (!IMG_Init(IMG_INIT_PNG)) {
//        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, IMG_GetError());
//        return EXIT_FAILURE;
//    }
//
//    //SDL_Surface* stickmanSurface = SDL_LoadBMP("../img/stickman.bmp");
////    SDL_Surface* stickmanSurface = IMG_Load("img/stickman.png");
////    if (!stickmanSurface) {
////        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
////        return EXIT_FAILURE;
////    }
//
////    SDL_Surface* optimizedSurface = SDL_ConvertSurface(stickmanSurface, surface->format);
////    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, optimizedSurface);
////    SDL_Rect strechRect;
////    strechRect.x = 0;
////    strechRect.y = 0;
////    strechRect.w = SCREEN_WIDTH;
////    strechRect.h = SCREEN_HEIGHT;
////    SDL_BlitSurfaceScaled(optimizedSurface, NULL, surface, &strechRect);
////    SDL_UpdateWindowSurface(window);
//    app* app = app_initialize();
//
//
//    button* play_button = button_initialize((window_surface->w / 2) - 50, (window_surface->h / 2) - 25, 100, 50,
//                                            0xFF, 0xFF, 0xFF, 0xAA,
//                                            renderer, font, "Play",
//                                            0xFF, 0x00, 0x00, 0xFF,
//                                            play);
//
//    paddle* paddle1 = paddle_initialize(10, 40, 20, 100,
//                                       0xFF, 0xFF, 0xFF, 0xFF);
//    paddle* paddle2 = paddle_initialize(window_surface->w - 30, 40, 20, 100,
//                                        0xFF, 0xFF, 0xFF, 0xFF);
//    paddle* paddles[2] = { paddle1, paddle2 };
//    ball* ball = ball_initialize((window_surface->w / 2), (window_surface->h / 2), 10, 0xFF, 0xFF, 0xFF, 0xFF);
//
//    srand(time(NULL));
//
//    SDL_Event e;
//    bool isRunning = true;
//    const float ticks_per_frame = 1000.f / SCREEN_FPS;
//
//    Uint32 totalFrameTicks = 0;
//    Uint32 totalFrames = 0;
//
//    while (isRunning) {
//        totalFrames++;
//        Uint64 startTicks = SDL_GetTicks();
//        Uint64 startPerf = SDL_GetPerformanceCounter();
//
//        // Events
//        event_loop();
//
//        // Physics
//        paddle_physics(paddle1, window_surface->w, window_surface->h);
//        paddle_physics(paddle2, window_surface->w, window_surface->h);
//        ball_physics(ball, window_surface->w, window_surface->h, paddles, 2);
//
//        // Render
//        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
//        SDL_RenderClear(renderer);
//        paddle_render(paddle1, renderer);
//        paddle_render(paddle2, renderer);
//        ball_render(ball, renderer);
//        button_render(play_button, renderer);
//
//        Uint64 endPerf = SDL_GetPerformanceCounter();
//
//        float elapsedMS = (endPerf - startPerf) / ((float)SDL_GetPerformanceFrequency() * 1000.f);
//        SDL_Delay(floor(ticks_per_frame - elapsedMS));
//        // End
//
//        Uint64 endTicks = SDL_GetTicks();
//        float frameTime = (endTicks - startTicks) / 1000.f;
//        totalFrameTicks += endTicks - startTicks;
//
//        SDL_Color textColor = { 255, 255, 255 };
//        char text[100];
//        snprintf(text, sizeof(text), "%s%.01f", "Current FPS: ", (1.f / frameTime));
//        text_render(renderer, font, text, textColor, 40, 10);
//        snprintf(text, sizeof(text), "%s%.01f", "Average FPS: ", (1000.f / ((float)totalFrameTicks / totalFrames)));
//        text_render(renderer, font, text, textColor, 40, 40);
//
//        SDL_RenderPresent(renderer);
//    }
//
//    paddle_free(paddle1);
//    paddle_free(paddle2);
//    ball_free(ball);
//    button_free(play_button);
//    SDL_DestroySurface(window_surface);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//
//    TTF_CloseFont(font);
//
//    TTF_Quit();
//    IMG_Quit();
//    SDL_QuitSubSystem(SDL_INIT_VIDEO);
//    return 0;
//}

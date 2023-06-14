#include "text.h"

#include <stdio.h>
#include <stdlib.h>

texture* text_texture(sdl_data* sdl_data, const char* text, SDL_Color color) {
    SDL_Renderer* renderer = sdl_data->renderer;
    TTF_Font* font = sdl_data->font;
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
    if (!textSurface) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
        return NULL;
    }
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (!textTexture) {
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
        return NULL;
    }
    texture* result = texture_initialize(textTexture, textSurface->w, textSurface->h);
    SDL_DestroySurface(textSurface);
    return result;
}

void text_render(sdl_data* sdl_data, const char* text, SDL_Color color, int x, int y) {
    SDL_Renderer* renderer = sdl_data->renderer;
    texture* textTexture = text_texture(sdl_data, text, color);
    if (!textTexture) {
        printf("Unable to render time texture!\n");
    }
    texture_render(textTexture, renderer, x, y);
    texture_free(textTexture);
}
